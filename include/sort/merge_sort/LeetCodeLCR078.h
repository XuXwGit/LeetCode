/*
LCR 078. 合并 K 个升序链表
困难
相关标签
相关企业
给定一个链表数组，每个链表都已经按升序排列。

请将所有链表合并到一个升序链表中，返回合并后的链表。
*/

#ifndef __LEETCODE_LCR_078_H__
#define __LEETCODE_LCR_078_H__

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
class SolutionLCR078 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* node = head;
        vector<ListNode*> ll = lists;
        bool flag = true;
        while(flag){
            flag = false;
            int min_val = INT_MAX;
            int min_index = -1;
            for(int i = 0; i<ll.size(); ++i){
                flag = flag || ll[i] != nullptr;
                if(ll[i] != nullptr && ll[i]->val < min_val){
                    min_val = ll[i]->val;
                    min_index = i;
                }
            }
            if (min_index != -1)
            {
                node->next = ll[min_index];
                node = node->next;
                ll[min_index] = ll[min_index]->next;
            }
        }
        return head->next;
    }
};


void test_LCR_078(){
    SolutionLCR078 solutionLCR078;
    vector<ListNode*> lists;
    ListNode* node = new ListNode(1);
    node->next = new ListNode(4);
    node->next->next = new ListNode(5);
    lists.push_back(node);

    node = new ListNode(1);
    node->next = new ListNode(3);
    node->next->next = new ListNode(4);
    lists.push_back(node);

    node = new ListNode(2);
    node->next = new ListNode(6);
    lists.push_back(node);

    ListNode* res = solutionLCR078.mergeKLists(lists);
    while(res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}

#endif // __LEETCODE_LCR_078_H__    