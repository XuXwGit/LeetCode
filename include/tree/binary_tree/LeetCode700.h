/*
700. 二叉搜索树中的搜索
已解答
简单

给定二叉搜索树（BST）的根节点 root 和一个整数值 val。

你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。
*/

#ifndef _BINARY_TREE_LEETCODE700_H_
#define _BINARY_TREE_LEETCODE700_H_


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
class Solution700 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root){
            return nullptr;
        }
        if(root->val == val){
            return root;
        }
        TreeNode* left = searchBST(root->left, val);
        TreeNode* right = searchBST(root->right, val);
        if(!left && !right){
            return nullptr;
        }
        return left ? left : right;
    }
};

void test700(){
    // [4,2,7,1,3]
    // 2
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    int val = 2;
    Solution700 solution;
    TreeNode* res = solution.searchBST(root, val);
    cout << res->val << endl;
}

#endif // !_BINARY_TREE_LEETCODE700_H_