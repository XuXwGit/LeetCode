/*
206. 反转链表
已解答
简单

给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
*/

#ifndef _LIST_LEETCODE206_H_
#define _LIST_LEETCODE206_H_


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution206 {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* third = second->next;
        first->next = nullptr;
        while(third){
            second->next = first;
            first = second;
            second = third;
            third = second->next; 
        }
        second->next = first;
        return second;
    }
};


void test206(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution206 sl;
    ListNode* res = sl.reverseList(head);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}

#endif // !_LIST_LEETCODE206_H_