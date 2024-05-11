#ifndef _LEETCODE_146_H_
#define _LEETCODE_146_H_

#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

class LRUCache {
private:
    struct DoubleListNode{
        int val;
        int key;
        DoubleListNode* pre;
        DoubleListNode* next;
        DoubleListNode():pre(nullptr), next(nullptr){}
        DoubleListNode(int key, int value):key(key), val(value),pre(nullptr), next(nullptr){}
    };
    DoubleListNode* head;
    DoubleListNode* tail;
    int capacity;
    map<int, DoubleListNode*> caches;
    void moveToHead(DoubleListNode* node){
        if(node == head->next){
            return;
        }

        removeNode(node);
        insertNode(node);
    }
    DoubleListNode* removeNode(DoubleListNode* node){
        node->next->pre = node->pre;
        node->pre->next = node->next;
        return node;
    }
    void insertNode(DoubleListNode* node){
        node->next = head->next;
        node->pre = head;
        node->next->pre = node;
        head->next = node;
    }
public:
    LRUCache(int capacity):capacity(capacity), head(new DoubleListNode()), tail(new DoubleListNode()){
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(caches.count(key)){
            moveToHead(caches[key]);
            return (caches[key])->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(caches.count(key)){
            caches[key]->val = value;
            moveToHead(caches[key]);
        }else{
            DoubleListNode* node = new DoubleListNode(key,value);
            insertNode(node);
            caches[key] = node;
            if(caches.size() > capacity){
                DoubleListNode* temp = removeNode(tail->pre);
                caches.erase(temp->key);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 // ["LRUCache","put","put","get","put","get","put","get","get","get"]
 // [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]

void test146() {
  LRUCache lru(2);
  lru.put(1, 1);
  lru.put(2, 2);
  cout << lru.get(1) << endl;
  lru.put(3, 3);
  cout << lru.get(2) << endl;
  lru.put(4, 4);
  cout << lru.get(1) << endl;
  cout << lru.get(3) << endl;
  cout << lru.get(4) << endl;
 }


#endif  // !_LEETCODE_146_H_
