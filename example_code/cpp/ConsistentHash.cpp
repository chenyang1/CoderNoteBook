#include <bits/stdc++.h>

using namespace std;

class ConsistentHash
{
private:
    unordered_set<string> physicalServer; // ��ʵ���������
    map<std::size_t, string> serverNodes; // hash ֵ�ͽڵ�ipӳ�䣨��ʵip��
    int virtualNodeNum;
    hash<string> hashStr; // �Դ��� hash ���� ����һ����Χ��size_t�ڵ���ֵ

public:
    ConsistentHash(int vnum) : virtualNodeNum(vnum){};
    void addNode(const string &ip)
    {
        physicalServer.insert(ip);
        // ��������ڵ��ʱ��Ҳ��������ڵ�
        for (int i = 0; i < virtualNodeNum; ++i)
        {
            stringstream key;
            key << ip << "#" << i;
            serverNodes.insert({hashStr(key.str()), ip});
        }
    }

    void delNode(const string &ip)
    {
        physicalServer.erase(ip);
        for (int i = 0; i < virtualNodeNum; ++i)
        {
            stringstream key;
            key << ip << "#" << i;
            serverNodes.erase(hashStr(key.str()));
        }
    }

    // ģ����������� hash string
    string virtualInsert(int data)
    {
        stringstream key;
        key << data;
        size_t hashKey = hashStr(key.str());
        // map::lower_bound(key) : ����map�е�һ�����ڻ����key�ĵ�����ָ��
        auto iter = serverNodes.lower_bound(hashKey);  
        if (iter == serverNodes.end())
        {
            return serverNodes.begin()->second;
        }
        return iter->second;
    }
};

// g++ ConsistentHash.c -std=c++11
// �����������һ������ 
int main()
{
    // ÿ���ڵ�����10������ڵ�
    ConsistentHash hash(10);
    hash.addNode("127.0.0.1");
    hash.addNode("127.0.0.2");
    hash.addNode("127.0.0.3");

    map<string, int> stats;
    for (int i = 0; i < 1000; ++i)
    {
        stats[hash.virtualInsert(i)]++;
    }

    for (auto &s : stats)
    {
        cout << s.first << " " << setprecision(2) << s.second / (1000 * 1.0) << endl;
    }
    return 0;
}