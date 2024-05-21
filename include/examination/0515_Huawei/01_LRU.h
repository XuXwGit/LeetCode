/*
2024.5.15-HW-第一题-塔子哥的操作系统作业
题目描述
塔子哥有一门专业课，叫做操作系统，简称OS。操作系统的页式存储管理中，当主存满并且需要的存储页不在主存中，需要对主存中的页面进行置换，其中有一个非常重要的算法，即LRU置换算法。

LRU (Least Recently Used)缓存算法理一种常用于管理缓存的策略，其目标是保留最近使用过的数据,而淘汰最久未被使用的数据。实现简单的LRU缓存算法,支持查询、插入、删除操作。

最久未被使用定义：查询、插入和删除操作均为一次访问操作，每个元素均有一个最后一次被访问时间,按照最后一次被访问时间排序，时间最早的即为最久未使用。插入操作：当缓存中已经存在，则刷新值，不存在，则插入，如果超过上限，则淘汰最久未被使用的元素。

输入描述
第一行两个数N和K，分别表示缓存内最多可以存放页数，以及操作序列中的总操作数。其中N∈[1,100]，K∈[1,10000]。

第二至第K+1行，每行两个输入，两个输入用空格分隔。第一个输入是一个字符𝑐ℎ_𝑖
 ：A表示插入，Q表示查询，D表示删除。第二个输入是一个整数𝑎_𝑖 ，表示一个页面的编号。其中𝑎_𝑖 ∈[1,100000]。

输出描述
输出一行，表示缓存内各页面的编号，按照从小到大排序。
*/

#ifndef _EXAMINATION_HUAWEI_0515_LRU_H_
#define _EXAMINATION_HUAWEI_0515_LRU_H_

struct doubleListNode{
    int val;
    doubleListNode* prev;
    doubleListNode* next;
    doubleListNode(int value): val(value), prev(nullptr), next(nullptr){
    }
};

class LRU0515{
private:
    int capacity;
    unordered_map<int, doubleListNode*> maps;
    doubleListNode* head;
    doubleListNode* tail;
public:
    LRU0515(int n):capacity(n), head(new doubleListNode(0)), tail(new doubleListNode(0)){
        head->next = tail;
        tail->prev = head;
    }

    void moveToHead(doubleListNode* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void remove(doubleListNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }

    void insert(int num){
        if(maps.count(num)){
            remove(maps[num]);
            moveToHead(maps[num]);
        }else{
            if((int)maps.size() == capacity){
                maps.erase(tail->prev->val);
                remove(tail->prev);
            }
            doubleListNode* node = new doubleListNode(num);
            moveToHead(node);
            maps[num] = node;
        }

        // print();
    }

    bool search(int num){
        if(maps.count(num)){
            remove(maps[num]);
            moveToHead(maps[num]);

            // print();
            return true;
        }else{
            return false;
        }
        return false;
    }

    void delet(int num){
        if(maps.count(num)){
            remove(maps[num]);
            doubleListNode* node = maps[num];
            maps.erase(num);
            delete node;
        }

        // print();
    }

    void print(){
        doubleListNode* node = head->next;
        while(node!= tail){
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }
};


void test_0515_01(){
    int n = 2;
    int k = 6;
    LRU0515 lru(n);
    for(int i = 0; i<k; ++i){
        char ch;
        int num;
        cin >> ch >> num;
        if(ch == 'A'){
            lru.insert(num);
        }else if(ch == 'Q'){
            if(lru.search(num)){
                cout << "true" << endl;
            }else{
                cout << "false" << endl;
            }
        }else if(ch == 'D'){
            lru.delet(num);
        }
    }
}

#endif // !_EXAMINATION_HUAWEI_0515_LRU_H_