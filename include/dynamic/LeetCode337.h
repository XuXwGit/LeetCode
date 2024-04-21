/*
337. 打家劫舍 III
// Hard

小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。

除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
*/


#ifndef _DYNAMIC_LEETCODE337_H_
#define _DYNAMIC_LEETCODE337_H_


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution337 {
private:
    map<TreeNode*, int> robmap;
public:
    int rob(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        if(robmap.count(root)){
            return robmap[root];
        }

        int money = root->val;
        money += root->left == nullptr ? 0: rob(root->left->left) + rob(root->left->right);
        money += root->right == nullptr ? 0: rob(root->right->left) + rob(root->right->right);

        robmap[root] = max(money, rob(root->left) + rob(root->right));
        return robmap[root];
    }
};



void test337(){
    Solution337 s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << s.rob(root) << endl;
    delete root->right->right;
    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;
}


#endif // !_DYNAMIC_LEETCODE337_H_