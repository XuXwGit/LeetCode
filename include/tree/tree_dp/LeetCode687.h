/*
687. 最长同值路径
已解答
中等
相关标签
相关企业
给定一个二叉树的 root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。 这条路径可以经过也可以不经过根节点。

两个节点之间的路径长度 由它们之间的边数表示。



示例 1:



输入：root = [5,4,5,1,1,5]
输出：2
示例 2:



输入：root = [1,4,5,4,4,5]
输出：2


提示:

树的节点数的范围是 [0, 104]
-1000 <= Node.val <= 1000
树的深度将不超过 1000
*/

#ifndef _LEETCODE_TREE_TREEDP_LEETCODE687_H_
#define _LEETCODE_TREE_TREEDP_LEETCODE687_H_
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
class Solution687
{
private:
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return -1;
        }
        int res1 = root->left && root->left->val == root->val ? dfs(root->left) : -1;
        int res2 = root->right && root->right->val == root->val ? dfs(root->right) : -1;
        return 1 + max(res1, res2);
    }

public:
    int longestUnivaluePath(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int res1 = dfs(root->left);
        int res2 = dfs(root->right);

        int res = 0;
        if (root->left && root->right)
        {
            if (root->val == root->left->val && root->val == root->right->val)
            {
                res = max(res, 2 + dfs(root->left) + dfs(root->right));
            }
            else if (root->val == root->left->val)
            {
                res = max(res, 1 + dfs(root->left));
            }
            else if (root->val == root->right->val)
            {
                res = max(res, 1 + dfs(root->right));
            }
        }
        else if (root->left)
        {
            if (root->val == root->left->val)
            {
                res = max(res, 1 + dfs(root->left));
            }
        }
        else if (root->right)
        {
            if (root->val == root->right->val)
            {
                res = max(res, 1 + dfs(root->right));
            }
        }

        res = max(res, longestUnivaluePath(root->left));
        res = max(res, longestUnivaluePath(root->right));

        return res;
    }
};

void test687()
{
    // [5,4,5,1,1,null,5]
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(5);
    Solution687 solution;
    cout << solution.longestUnivaluePath(root) << endl;

    // [1,4,5,4,4,null,5]
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(5);
    cout << solution.longestUnivaluePath(root2) << endl;
}

#endif // !_LEETCODE_TREE_TREEDP_LEETCODE687_H_