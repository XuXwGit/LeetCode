/*
2192. 有向无环图中一个节点的所有祖先
已解答
中等
相关标签
相关企业
提示
给你一个正整数 n ，它表示一个 有向无环图 中节点的数目，节点编号为 0 到 n - 1 （包括两者）。

给你一个二维整数数组 edges ，其中 edges[i] = [fromi, toi] 表示图中一条从 fromi 到 toi 的单向边。

请你返回一个数组 answer，其中 answer[i]是第 i 个节点的所有 祖先 ，这些祖先节点 升序 排序。

如果 u 通过一系列边，能够到达 v ，那么我们称节点 u 是节点 v 的 祖先 节点。



示例 1：



输入：n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
输出：[[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
解释：
上图为输入所对应的图。
- 节点 0 ，1 和 2 没有任何祖先。
- 节点 3 有 2 个祖先 0 和 1 。
- 节点 4 有 2 个祖先 0 和 2 。
- 节点 5 有 3 个祖先 0 ，1 和 3 。
- 节点 6 有 5 个祖先 0 ，1 ，2 ，3 和 4 。
- 节点 7 有 4 个祖先 0 ，1 ，2 和 3 。
示例 2：



输入：n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
输出：[[],[0],[0,1],[0,1,2],[0,1,2,3]]
解释：
上图为输入所对应的图。
- 节点 0 没有任何祖先。
- 节点 1 有 1 个祖先 0 。
- 节点 2 有 2 个祖先 0 和 1 。
- 节点 3 有 3 个祖先 0 ，1 和 2 。
- 节点 4 有 4 个祖先 0 ，1 ，2 和 3 。


提示：

1 <= n <= 1000
0 <= edges.length <= min(2000, n * (n - 1) / 2)
edges[i].length == 2
0 <= fromi, toi <= n - 1
fromi != toi
图中不会有重边。
图是 有向 且 无环 的。
*/

#ifndef _LEETCODE_GRAPH_DFS_LEETCODE2192_H_
#define _LEETCODE_GRAPH_DFS_LEETCODE2192_H_

class Solution2192
{
private:
    void dfs(int i, vector<bool> &visited, vector<int> &parents, unordered_map<int, vector<int>> &graph)
    {
        if (visited[i])
        {
            return;
        }

        visited[i] = true;

        for (int j : graph[i])
        {
            if (visited[j])
            {
                continue;
            }
            parents.push_back(j);
            dfs(j, visited, parents, graph);
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> graph;

        for (auto x : edges)
        {
            graph[x[1]].push_back(x[0]);
        }

        vector<vector<int>> res;
        for (int i = 0; i < n; ++i)
        {
            vector<bool> visited(n, false);
            vector<int> sol;
            dfs(i, visited, sol, graph);
            res.emplace_back(sol.begin(), sol.end());
            sort(res[i].begin(), res[i].end());
        }

        return res;
    }
};

void test2192()
{
    int n = 8;
    vector<vector<int>> edgeList = {{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6}};
    Solution2192 solution2192;
    vector<vector<int>> res = solution2192.getAncestors(n, edgeList);
    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}

#endif // !_LEETCODE_GRAPH_DFS_LEETCODE2192_H_