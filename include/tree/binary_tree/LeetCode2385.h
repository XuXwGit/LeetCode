/*
2385. 感染二叉树需要的总时间
尝试过

给你一棵二叉树的根节点 root ，二叉树中节点的值 互不相同 。另给你一个整数 start 。在第 0 分钟，感染 将会从值为 start 的节点开始爆发。

每分钟，如果节点满足以下全部条件，就会被感染：

节点此前还没有感染。
节点与一个已感染节点相邻。
返回感染整棵树需要的分
*/


#ifndef _TREE_BINARY_TREE_LEETCODE2385_H_
#define _TREE_BINARY_TREE_LEETCODE2385_H_

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
class Solution2385 {
private:
    void dfs(map<int, vector<int>>& graph, TreeNode* root){
        if(!root){
            return;
        }

        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            dfs(graph, root->left);
        }

        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            dfs(graph, root->right);
        }
    }
    void dijkstra(map<int, vector<int>>& graph, map<int, int>& distance, int start){
        distance[start] = 0;
        priority_queue<pair<int, int>> pq;
        pq.emplace(0, start);
        while(!pq.empty()){
            int curr_dis = pq.top().first;
            int curr_val = pq.top().second;
            pq.pop();
            if(curr_dis > distance[curr_val]){
                continue;
            }

            for(const auto x: graph[curr_val]){
                if(curr_dis + 1 < distance[x]){
                    distance[x] = curr_dis + 1;
                    pq.emplace(distance[x], x);
                }
            }
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<int, vector<int>> graph;
        dfs(graph, root);
        int n = graph.size();
        map<int, int> distance;
        for(auto x: graph){
            distance[x.first] = INT_MAX/2;
        }
        dijkstra(graph, distance, start);
        int max_len = 0;
        for(auto x: distance){
            max_len = max(max_len, x.second);
        }

        return max_len;
    }
};


void test2385(){
    Solution2385 solution2385;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << solution2385.amountOfTime(root, 1) << endl;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
}


#endif // !_TREE_BINARY_TREE_LEETCODE2385_H_