#ifndef __LOCKFREE_STACK_H__
#define __LOCKFREE_STACK_H__

class Node 
{
    public:
        int val;
        int extra_info;

        Node *next;
        Node(int val): val(val), next(NULL) {}
};

class Stack 
{
    public:
        void push(int val, int debug_thread_info);
        Node* pop();
        void print();
        int get_size();
        
private:
    std::atomic<Node*> _top;
};

#endif 
