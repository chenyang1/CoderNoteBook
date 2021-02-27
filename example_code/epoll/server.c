#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define MAX_EVENTS 1000
#define MAX_LEN 1024

/*
�ο� man epoll_ctl
EPOLLIN �ɶ�
EPOLLOUT ��д
EPOLLPRI ��������
EPOLLRDHUP ���� 
EPOLLERR ����
EPOLLHUP ����
*/

//���÷�����
static void setnonblocking(int sockfd)
{
    int flag = fcntl(sockfd, F_GETFL, 0);
    if (flag < 0)
    {
        perror("fcntl F_GETFL fail");
        return;
    }
    if (fcntl(sockfd, F_SETFL, flag | O_NONBLOCK) < 0)
    {
        perror("fcntl F_SETFL fail");
    }
}

//���epoll�¼�
static int epoll_add(int efd, int sockfd)
{
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = sockfd;
    if (-1 == epoll_ctl(efd, EPOLL_CTL_ADD, sockfd, &ev))
    {
        perror("epoll_ctl EPOLL_CTL_ADD fail");
        return 1;
    }
    return 0;
}

//�޸�epoll�¼�,Ĭ��LT
static void epoll_write(int efd, int sockfd, bool enable)
{
    struct epoll_event ev;
    ev.events = EPOLLIN | (enable ? EPOLLOUT : 0);
    ev.data.fd = sockfd;
    epoll_ctl(efd, EPOLL_CTL_MOD, sockfd, &ev);
}

//ɾ��epoll�¼�
static void epoll_del(int efd, int sockfd)
{
    perror("close by");
    epoll_ctl(efd, EPOLL_CTL_DEL, sockfd, NULL);
    close(sockfd);
}

//��,����
int readn(int fd, void *vptr, size_t n)
{
    // see man 2 read
    size_t nleft;
    int nread;
    char *ptr;

    ptr = (char *)vptr;
    nleft = n;
    while (nleft > 0)
    {
        nread = (int)read(fd, ptr, nleft);
        if (nread < 0)
        {
            if (errno == EINTR)
                nread = 0; /* call read() again */
            else
                return -1; /* maybe errno == EAGAIN */
        }
        else if (0 == nread)
        {
            break; /* EOF */
        }
        nleft -= nread;
        ptr += nread;
    }
    return (n - nleft); /* return >= 0 */
}

//д,����
int writen(int fd, const void *vptr, size_t n)
{
    // see man 2 write
    size_t nleft;
    int nwritten;
    const char *ptr;

    ptr = (char *)vptr;
    nleft = n;
    while (nleft > 0)
    {
        nwritten = write(fd, ptr, nleft);
        if (nwritten <= 0)
        {
            if (nwritten < 0 && errno == EINTR)
                nwritten = 0; /* call write() again */
            else
                return (-1); /* error */
        }
        nleft -= nwritten;
        ptr += nwritten;
    }
    return (n);
}

int main()
{
    // socket
    int listenfd;
    struct sockaddr_in servaddr;
    short port = 9527;

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    setnonblocking(listenfd); // accept����ʱ������
    int res = bind(listenfd, (sockaddr *)&servaddr, sizeof(servaddr));
    if (0 == res)
        printf("server bind success, 0.0.0.0:%d\n", port);
    else
    {
        perror("bind fail");
        exit(EXIT_FAILURE);
    }
    res = listen(listenfd, 100);
    if (0 == res)
        printf("server listen success\n");
    else
    {
        perror("listen fail");
        exit(EXIT_FAILURE);
    }

    // epoll create,see man epoll_create
    struct epoll_event ev, events[MAX_EVENTS];
    int epollfd = epoll_create(10);
    if (-1 == epollfd)
    {
        perror("epoll_create fail");
        exit(EXIT_FAILURE);
    }

    // epoll add
    if (epoll_add(epollfd, listenfd))
    {
        exit(EXIT_FAILURE);
    }

    for (;;)
    {
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (-1 == nfds)
        {
            perror("epoll_wait fail");
            exit(EXIT_FAILURE);
        }
        for (int n = 0; n < nfds; ++n)
        {
            if (events[n].data.fd == listenfd)
            {
                struct sockaddr_in cliaddr;
                socklen_t len = sizeof(cliaddr);
                int connfd = accept(listenfd, (sockaddr *)&cliaddr, &len);
                if (-1 == connfd)
                {
                    perror("accept fail");
                    continue;
                }
                setnonblocking(connfd);
                if (epoll_add(epollfd, connfd))
                {
                    close(connfd);
                    continue;
                }

                // �������һЩ����,�������cliaddr
                char buff[INET_ADDRSTRLEN + 1] = {0};
                inet_ntop(AF_INET, &cliaddr.sin_addr, buff, INET_ADDRSTRLEN);
                uint16_t port = ntohs(cliaddr.sin_port);
                printf("connection from %s, port %d\n", buff, port);
            }
            else if (events[n].events & EPOLLIN)
            {
                char buffer[MAX_LEN + 1] = {0}; /* keep the end '\0' */
                size_t count = MAX_LEN;
                int connfd = events[n].data.fd;
                int res = readn(connfd, buffer, count);

                // ���������쳣���
                if (res < 0 && errno != EAGAIN)
                {
                    epoll_del(epollfd, connfd);
                    continue;
                }
                else if (0 == res)
                {
                    epoll_del(epollfd, connfd);
                    continue;
                }

                if (strlen(buffer) != 0)
                {
                    printf("fd:%d, read len:%ld\n", connfd, strlen(buffer));
                }

                // ����Ҫ��������,ע��EPOLLOUT
                if (strlen(buffer) != 0)
                    epoll_write(epollfd, connfd, true);
            }
            else if (events[n].events & EPOLLOUT)
            {
                const char *vptr = "hi client!"; /* α��ķ������� */
                int connfd = events[n].data.fd;
                size_t count = strlen(vptr);
                int len = writen(connfd, vptr, count);

                // ���������쳣���
                if (len < 0 && errno != EAGAIN)
                {
                    epoll_del(epollfd, connfd);
                    continue;
                }

                if (len > 0)
                {
                    printf("fd:%d, write len:%d\n", connfd, len);
                }

                if (len < count)
                {
                    epoll_write(epollfd, connfd, true); /* ���п�д����,ע��EPOLLOUT */
                }
                else
                {
                    epoll_write(epollfd, connfd, false); /* �Ѿ�û�п�д����,ע��EPOLLIN */
                }
            }
            else if (events[n].events & EPOLLPRI)
            {
                // pass
            }
            else if (events[n].events & EPOLLRDHUP)
            {
                epoll_del(epollfd, events[n].data.fd);
            }
            else if (events[n].events & EPOLLERR)
            {
                epoll_del(epollfd, events[n].data.fd);
            }
            else if (events[n].events & EPOLLHUP)
            {
                epoll_del(epollfd, events[n].data.fd);
            }
            else
            {
                // pass
            }
        }
    }
}