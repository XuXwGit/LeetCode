#ifndef _LEETCODE_77_H_
#define _LEETCODE_77_H_

#include <iostream>

 ////Definition for singly-linked list.
 //struct ListNode {
 //    int val;
 //    ListNode *next;
 //    ListNode() : val(0), next(nullptr) {}
 //    ListNode(int x) : val(x), next(nullptr) {}
 //    ListNode(int x, ListNode *next) : val(x), next(next) {}
 //};
 
class Solution77 {
 public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode* head1 = head;
    ListNode* head2 = split(head);

    return merge(sortList(head1), sortList(head2));
  }

  ListNode* split(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* second_part = slow->next;
    slow->next = nullptr;

    return second_part;
  }

  ListNode* merge(ListNode* list1, ListNode* list2) {
    if (!list1 && !list2) {
      return nullptr;
    } else if (!list1 && list2) {
      return list2;
    } else if (list1 && !list2) {
      return list1;
    }

    ListNode* head = list1->val < list2->val ? list1 : list2;
    ListNode* curr = head;
    if (list1->val < list2->val) {
      list1 = list1->next;
    } else {
      list2 = list2->next;
    }

    while (list1 && list2) {
      if (list1->val < list2->val) {
        curr->next = list1;
        list1 = list1->next;
      } else {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;
    }
    curr->next = list1 ? list1 : list2;

    return head;
  }
};

void test77() {
  ListNode* head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(3);

  Solution77 solution;
  ListNode* result = solution.sortList(head);
  while (result) {
	std::cout << result->val << " ";
	result = result->next;
  }
  std::cout << std::endl;
}

#endif  // !_LEETCODE_77_H_
