#ifndef _LEETCODE_25_H_
#define _LEETCODE_25_H_

#include <stack>
#include <vector>
#include <iostream>

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution25 {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* first = nullptr;
    ListNode* front = nullptr;
    ListNode* back = head;
    stack<ListNode*> stac;
    ListNode* temp = back;

    int flag = 1;

    while (flag) {
      back = temp;
      for (int i = 0; i < k && temp; i++) {
        stac.push(temp);
        if (i == k - 1) {
          flag++;
          if (flag == 2) {
            first = temp;
          }
        }
        if (temp) {
            temp = temp->next;
        }
        else {
			break;
        }
      }
      if (stac.size() < k) {
        front->next = back;
        break;
      }

      while (!stac.empty()) {
        if (front) {
          front->next = stac.top();
        }
        front = stac.top();
        stac.pop();
      }

      front->next = temp;
    }

    return first;
  }
};


void test25() { 
    vector<int> head = {1, 2, 3, 4, 5}; 
    ListNode *temp = new ListNode(head.front()); 
    ListNode *temp2 = temp;
    for (int i = 1; i < head.size(); i++) {
        temp->next = new ListNode(head[i]);
        temp = temp->next;
     }
     int k = 2;

Solution25 s = Solution25();
ListNode *res = s.reverseKGroup(temp2, k);
while (res) {
	cout << res->val << " ";
	res = res->next;    
    }
}
#endif  // !_LEETCODE_25_H_
