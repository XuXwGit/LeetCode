/*
1786. 从第一个节点出发到最后一个节点的受限路径数
中等
相关标签
相关企业
提示
现有一个加权无向连通图。给你一个正整数 n ，表示图中有 n 个节点，并按从 1 到 n 给节点编号；另给你一个数组 edges ，其中每个 edges[i] = [ui, vi, weighti] 表示存在一条位于节点 ui 和 vi 之间的边，这条边的权重为 weighti 。

从节点 start 出发到节点 end 的路径是一个形如 [z0, z1, z2, ..., zk] 的节点序列，满足 z0 = start 、zk = end 且在所有符合 0 <= i <= k-1 的节点 zi 和 zi+1 之间存在一条边。

路径的距离定义为这条路径上所有边的权重总和。用 distanceToLastNode(x) 表示节点 n 和 x 之间路径的最短距离。受限路径 为满足 distanceToLastNode(zi) > distanceToLastNode(zi+1) 的一条路径，其中 0 <= i <= k-1 。

返回从节点 1 出发到节点 n 的 受限路径数 。由于数字可能很大，请返回对 109 + 7 取余 的结果。



示例 1：


输入：n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
输出：3
解释：每个圆包含黑色的节点编号和蓝色的 distanceToLastNode 值。三条受限路径分别是：
1) 1 --> 2 --> 5
2) 1 --> 2 --> 3 --> 5
3) 1 --> 3 --> 5
示例 2：


输入：n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
输出：1
解释：每个圆包含黑色的节点编号和蓝色的 distanceToLastNode 值。唯一一条受限路径是：1 --> 3 --> 7 。


提示：

1 <= n <= 2 * 104
n - 1 <= edges.length <= 4 * 104
edges[i].length == 3
1 <= ui, vi <= n
ui != vi
1 <= weighti <= 105
任意两个节点之间至多存在一条边
任意两个节点之间至少存在一条路径
*/

#ifndef _LEETCODE_GRAPH_SHORTEST_PATH_DIJKSTRA_LEETCODE1786_H_
#define _LEETCODE_GRAPH_SHORTEST_PATH_DIJKSTRA_LEETCODE1786_H_

class Solution1786
{
private:
    int n;
    unordered_map<int, vector<pair<int, int>>> graph;
    void dijkstra(int source, vector<int> &distance)
    {
        distance[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, source);
        while (!pq.empty())
        {
            auto [dis, idx] = pq.top();
            pq.pop();
            if (distance[idx] < dis)
            {
                continue;
            }

            for (auto [y, cost] : graph[idx])
            {
                if (distance[y] > dis + cost)
                {
                    distance[y] = dis + cost;
                    pq.emplace(distance[y], y);
                }
            }
        }
    }
    int dfs(int i)
    {
        if (i == n - 1)
        {
            return 1;
        }

        if (mem[i] >= 0)
        {
            return mem[i];
        }

        mem[i] = 0;
        for (auto [y, cost] : graph[i])
        {
            if (distance[i] > distance[y])
            {
                mem[i] += dfs(y);
                mem[i] %= mod;
            }
        }

        return mem[i];
    }

    int DP()
    {
        vector<pair<int, int>> maps;
        for (int i = 0; i < n; ++i)
        {
            maps.emplace_back(distance[i], i);
        }
        sort(maps.begin(), maps.end());

        vector<int> dp(n, 0);
        dp[n - 1] = 1;
        for (int i = 0; i < maps.size(); ++i)
        {
            int curr = maps[i].second;
            int dist = maps[i].first;
            for (auto [y, cos] : graph[curr])
            {
                if (dist > distance[y])
                {
                    dp[curr] += dp[y];
                    dp[curr] %= mod;
                }
            }

            if (curr == 0)
            {
                return dp[0];
            }
        }

        return dp[0];
    }

    vector<int> distance;
    vector<int> mem;
    const int mod = 1e9 + 7;

public:
    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        this->n = n;
        for (auto x : edges)
        {
            graph[x[0] - 1].emplace_back(x[1] - 1, x[2]);
            graph[x[1] - 1].emplace_back(x[0] - 1, x[2]);
        }

        distance = vector<int>(n, INT_MAX);
        dijkstra(n - 1, distance);

        mem = vector<int>(n, -1);

        return dfs(0);
        // return DP();
    }
};

void test1786()
{
    Solution1786 solution1786;
    vector<vector<int>> edges = {{1, 2, 3}, {1, 3, 4}, {2, 3, 1}, {3, 4, 1}};
    cout << solution1786.countRestrictedPaths(4, edges) << endl;
}

#endif // !_LEETCODE_GRAPH_SHORTEST_PATH_DIJKSTRA_LEETCODE1876_H_