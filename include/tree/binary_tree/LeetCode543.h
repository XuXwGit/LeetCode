/*
543. 二叉树的直径
已解答

给你一棵二叉树的根节点，返回该树的 直径 。

二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。

两节点之间路径的 长度 由它们之间边数表示。
*/


#ifndef _TREE_BINARY_TREE_LEETCODE543_H_
#define _TREE_BINARY_TREE_LEETCODE543_H_


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
class Solution543 {
private:
    int maxLen = 0;
    int dfs(TreeNode* root){
        if(!root){
            return -1;
        }
        int subLeft = dfs(root->left) + 1;
        int subRight = dfs(root->right) + 1;
        maxLen = max(maxLen, subLeft + subRight);
        return max(subLeft, subRight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxLen;
    }
};

void test543(){
    // [4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(-7);
    root->right = new TreeNode(-3);
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->right->left = new TreeNode(-9);
    root->right->right = new TreeNode(-3);
    root->right->left->left = new TreeNode(9);
    root->right->left->right = new TreeNode(-7);
    root->right->right->left = new TreeNode(-4);
    root->right->right->right = nullptr;
    root->right->left->left->left = new TreeNode(6);
    root->right->left->left->right = nullptr;
    root->right->left->right->left = new TreeNode(-6);
    root->right->left->right->right = new TreeNode(-6);
    root->right->left->left->left->left = nullptr;
    root->right->left->left->left->right = new TreeNode(0);
    root->right->left->right->left->left = new TreeNode(6);
    root->right->left->right->left->right = new TreeNode(5);
    root->right->left->right->right->left = nullptr;
    root->right->left->right->right->right = new TreeNode(9);
    root->right->left->right->left->left->left = nullptr;
    root->right->left->right->left->left->right = new TreeNode(-1);
    root->right->left->right->left->right->left = new TreeNode(-4);
    root->right->left->right->left->right->right = nullptr;
    root->right->left->right->left->left->right->left = nullptr;
    root->right->left->right->left->left->right->right = new TreeNode(-2);
    Solution543 solution543;
    cout << solution543.diameterOfBinaryTree(root) << endl;
}

#endif // !_TREE_BINARY_TREE_LEETCODE543_H_