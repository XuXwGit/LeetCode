/*
1192. 查找集群内的关键连接
已解答
困难
相关标签
相关企业
提示
力扣数据中心有 n 台服务器，分别按从 0 到 n-1 的方式进行了编号。它们之间以 服务器到服务器 的形式相互连接组成了一个内部集群，连接是无向的。用  connections 表示集群网络，connections[i] = [a, b] 表示服务器 a 和 b 之间形成连接。任何服务器都可以直接或者间接地通过网络到达任何其他服务器。

关键连接 是在该集群中的重要连接，假如我们将它移除，便会导致某些服务器无法访问其他服务器。

请你以任意顺序返回该集群内的所有 关键连接 。



示例 1：



输入：n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
输出：[[1,3]]
解释：[[3,1]] 也是正确的。
示例 2:

输入：n = 2, connections = [[0,1]]
输出：[[0,1]]


提示：

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
不存在重复的连接
*/

#ifndef __LEETCODE_GRAPH_TARJAN_LEETCODE_1192_H__
#define __LEETCODE_GRAPH_TARJAN_LEETCODE_1192_H__

class Solution1192
{
private:
    void dfs(int u, int parent, unordered_map<int, vector<int>> &graph, vector<int> &time, vector<int> &group, vector<vector<int>> &res, int num)
    {
        group[u] = time[u] = ++num;
        for (int v : graph[u])
        {
            if (time[v] < 0)
            {
                dfs(v, u, graph, time, group, res, num);
                group[u] = min(group[u], group[v]);
                if (group[v] > time[u])
                {
                    res.emplace_back(vector<int>{u, v});
                }
            }
            else if (time[v] < time[u] && v != parent)
            {
                group[u] = min(group[u], time[v]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        // build graph
        unordered_map<int, vector<int>> graph;
        for (auto edge : connections)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> time(n, -1);
        vector<int> group(n, -1);
        int num = 0;

        vector<vector<int>> res;
        dfs(0, 0, graph, time, group, res, num);

        return res;
    }
};

void test1192()
{
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    Solution1192 solution;
    vector<vector<int>> res = solution.criticalConnections(n, connections);
    for (auto edge : res)
    {
        cout << "[" << edge[0] << ", " << edge[1] << "]" << endl;
    }
}

#endif // !__LEETCODE_GRAPH_TARJAN_LEETCODE_1192_H__