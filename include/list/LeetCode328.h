/*
328. 奇偶链表
中等

给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。

第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。

请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。

你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。
*/

#ifndef _LIST_LEETCODE328_H_
#define _LIST_LEETCODE328_H_


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
class Solution328 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return head;
        }

        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* node1 = first;
        ListNode* node2 = second;
        ListNode* node = second;
        while(node){
            if(node->next){
                node1->next = node->next;
                node = node->next;
                node1 = node1->next;
            }
            if(node->next){
                node2->next = node->next;
                node = node->next;
                node2 = node2->next;
            }
        }
        node1->next = second;

        return first;
    }
};


void test328(){
    Solution328 solution328;
    ListNode* head = new ListNode(1);
    ListNode* node = head;
    for(int i = 2; i<=5; ++i){
        node->next = new ListNode(i);
        node = node->next;
    }
    ListNode* res = solution328.oddEvenList(head);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}




#endif // !_LIST_LEETCODE328_H_