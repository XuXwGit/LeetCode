/*
2876. 有向图访问计数
困难
相关标签
相关企业
提示
现有一个有向图，其中包含 n 个节点，节点编号从 0 到 n - 1 。此外，该图还包含了 n 条有向边。

给你一个下标从 0 开始的数组 edges ，其中 edges[i] 表示存在一条从节点 i 到节点 edges[i] 的边。

想象在图上发生以下过程：

你从节点 x 开始，通过边访问其他节点，直到你在 此过程 中再次访问到之前已经访问过的节点。
返回数组 answer 作为答案，其中 answer[i] 表示如果从节点 i 开始执行该过程，你可以访问到的不同节点数。



示例 1：


输入：edges = [1,2,0,0]
输出：[3,3,3,4]
解释：从每个节点开始执行该过程，记录如下：
- 从节点 0 开始，访问节点 0 -> 1 -> 2 -> 0 。访问的不同节点数是 3 。
- 从节点 1 开始，访问节点 1 -> 2 -> 0 -> 1 。访问的不同节点数是 3 。
- 从节点 2 开始，访问节点 2 -> 0 -> 1 -> 2 。访问的不同节点数是 3 。
- 从节点 3 开始，访问节点 3 -> 0 -> 1 -> 2 -> 0 。访问的不同节点数是 4 。
示例 2：


输入：edges = [1,2,3,4,0]
输出：[5,5,5,5,5]
解释：无论从哪个节点开始，在这个过程中，都可以访问到图中的每一个节点。


提示：

n == edges.length
2 <= n <= 105
0 <= edges[i] <= n - 1
edges[i] != i

*/

#ifndef _GRAPH_PSEUDOTREE_LEETCODE2876_H_
#define _GRAPH_PSEUDOTREE_LEETCODE2876_H_

class Solution2876
{
private:
    int dfs(int i, vector<int> &edges, vector<bool> &visited, vector<int> &res)
    {
        if (res[i] >= 0)
        {
            return res[i];
        }
        res[i] = dfs(edges[i], edges, visited, res) + 1;
        visited[i] = false;

        return res[i];
    }

public:
    vector<int> countVisitedNodes(vector<int> &edges)
    {
        int n = edges.size();

        vector<int> indegrees(n, 0);

        for (int x : edges)
        {
            indegrees[x]++;
        }

        vector<bool> visited(n, false);

        queue<int> zeros;
        for (int i = 0; i < n; ++i)
        {
            if (indegrees[i] == 0)
            {
                visited[i] = true;
                zeros.push(i);
            }
        }

        while (!zeros.empty())
        {
            int curr = zeros.front();
            zeros.pop();

            int next = edges[curr];

            if ((--indegrees[next]) == 0)
            {
                zeros.push(next);
                visited[next] = true;
            }
        }

        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (visited[i])
            {
                continue;
            }

            int curr = i;
            vector<int> cycle;
            while (edges[curr] != i)
            {
                cycle.push_back(curr);
                curr = edges[curr];
            }
            cycle.push_back(curr);
            for (auto x : cycle)
            {
                res[x] = cycle.size();
                visited[x] = true;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            dfs(i, edges, visited, res);
        }

        return res;
    }
};

void test2876()
{
    vector<int> edges = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Solution2876 solution2876;
    vector<int> res = solution2876.countVisitedNodes(edges);
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;
}

#endif // _GRAPH_PSEUDOTREE_LEETCODE2876_H_