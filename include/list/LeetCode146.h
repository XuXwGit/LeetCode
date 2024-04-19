#ifndef _LEETCODE_146_H_
#define _LEETCODE_146_H_

#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

struct DoubleLinkNode {
  int val;
  DoubleLinkNode* prev;
  DoubleLinkNode* next;
  DoubleLinkNode() : val(0), prev(nullptr), next(nullptr) {}
  DoubleLinkNode(int value) : val(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
 private:
  int capacity;
  int num_nodes;
  unordered_map<int, DoubleLinkNode*> map;
  DoubleLinkNode* head;
  DoubleLinkNode* tail;

  void removeNode(DoubleLinkNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  DoubleLinkNode* moveToHead(DoubleLinkNode* node) {
    removeNode(node);
    return addToHead(node);
  }

  DoubleLinkNode* addToHead(DoubleLinkNode* node) {
    head->next->prev = node;
    node->next = head->next;
    head->next = node;
    node->prev = head;
    return node;
  }

  DoubleLinkNode* removeTail() {
    removeNode(tail->prev);
    return tail;
  }

 public:
  LRUCache(int capacity) : capacity(capacity), num_nodes(0) {
    head = new DoubleLinkNode();
    tail = new DoubleLinkNode();

    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (map.find(key) != map.end()) {
      return moveToHead(map[key])->val;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (map.find(key) != map.end()) {
      map[key]->val = value;
      moveToHead(map[key]);
      return;
    } else {
      DoubleLinkNode* new_node = new DoubleLinkNode(value);
      map[key] = new_node;
      addToHead(new_node);
      if (num_nodes < capacity) {
        num_nodes++;
      } else {
        // delete tail node
        removeTail();
      }
      return;
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
