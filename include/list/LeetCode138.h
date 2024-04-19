#include <cstddef>
#include <iostream>
#ifndef _LEETCODE_138_H_
#define _LEETCODE_138_H_


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution138 {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) {
      return NULL;
    }

    Node* temp = head;
    while (temp) {
      Node* node = new Node(temp->val);
      node->next = temp->next;
      node->random = temp->random;
      temp->next = node;
      temp = node->next;
    }

    temp = head->next;
    while (temp) {
    if(temp->random) {
		temp->random = temp->random->next;
	  }
    if (temp->next) {
        temp = temp->next->next;
        } else {
        temp = NULL;
        }
    }

     temp = head;
    Node* temp2 = head;
    Node* ans = head->next;
    while (temp && temp2) {
      temp->next = temp2->next;
      temp = temp2->next;
      if (temp) {
        temp2->next = temp->next;
        temp2 = temp->next;
      }
    }

    return ans;
  }
};

void test138() {
  Node* head = new Node(7);
  Node* node1 = new Node(13);
  Node* node2 = new Node(11);
  Node* node3 = new Node(10);
  Node* node4 = new Node(1);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node1->random = head;
  node2->random = node4;
  node3->random = node2;
  node4->random = head;
  Solution138 solution138;
  Node* ans = solution138.copyRandomList(head);
  while (ans) {
	std::cout << ans->val << " ";
	ans = ans->next;
  }
  std::cout << std::endl;
}

#endif  // !_LEETCODE_138_H_
