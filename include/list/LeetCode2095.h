/*
2095. 删除链表的中间节点
已解答

给你一个链表的头节点 head 。删除 链表的 中间节点 ，并返回修改后的链表的头节点 head 。

长度为 n 链表的中间节点是从头数起第 ⌊n / 2⌋ 个节点（下标从 0 开始），其中 ⌊x⌋ 表示小于或等于 x 的最大整数。

对于 n = 1、2、3、4 和 5 的情况，中间节点的下标分别是 0、1、1、2 和 2 。
*/

#ifndef _LIST_LEETCODE2095_H_
#define _LIST_LEETCODE2095_H_

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
class Solution2095 {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int len = 0;
        ListNode* node = head;
        while(node){
            len ++;
            node = node->next;
        }

        len = len/2;

        if(!len){
            return nullptr;
        }
        
        node = head;
        while(len){
            if(len == 1){
                ListNode* temp = node->next;
                node->next = node->next->next;
                delete temp;
                break;
            }
            node = node->next;
            len--;
        }

        return head;
    }
};


void test2095(){
    Solution2095 solution2095;
    ListNode* head = new ListNode(1);
    ListNode* node = head;
    for(int i = 2; i<=5; ++i){
        node->next = new ListNode(i);
        node = node->next;
    }

    ListNode* res = solution2095.deleteMiddle(head);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}

#endif // !_LIST_LEETCODE2095_H_
