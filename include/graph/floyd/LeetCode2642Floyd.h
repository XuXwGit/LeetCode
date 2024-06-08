/*
2642. 设计可以求最短路径的图类
已解答
困难
相关标签
相关企业
提示
给你一个有 n 个节点的 有向带权 图，节点编号为 0 到 n - 1 。图中的初始边用数组 edges 表示，其中 edges[i] = [fromi, toi, edgeCosti] 表示从 fromi 到 toi 有一条代价为 edgeCosti 的边。

请你实现一个 Graph 类：

Graph(int n, int[][] edges) 初始化图有 n 个节点，并输入初始边。
addEdge(int[] edge) 向边集中添加一条边，其中 edge = [from, to, edgeCost] 。数据保证添加这条边之前对应的两个节点之间没有有向边。
int shortestPath(int node1, int node2) 返回从节点 node1 到 node2 的路径 最小 代价。如果路径不存在，返回 -1 。一条路径的代价是路径中所有边代价之和。


示例 1：



输入：
["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
[[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]
输出：
[null, 6, -1, null, 6]

解释：
Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
g.shortestPath(3, 2); // 返回 6 。从 3 到 2 的最短路径如第一幅图所示：3 -> 0 -> 1 -> 2 ，总代价为 3 + 2 + 1 = 6 。
g.shortestPath(0, 3); // 返回 -1 。没有从 0 到 3 的路径。
g.addEdge([1, 3, 4]); // 添加一条节点 1 到节点 3 的边，得到第二幅图。
g.shortestPath(0, 3); // 返回 6 。从 0 到 3 的最短路径为 0 -> 1 -> 3 ，总代价为 2 + 4 = 6 。


提示：

1 <= n <= 100
0 <= edges.length <= n * (n - 1)
edges[i].length == edge.length == 3
0 <= fromi, toi, from, to, node1, node2 <= n - 1
1 <= edgeCosti, edgeCost <= 106
图中任何时候都不会有重边和自环。
调用 addEdge 至多 100 次。
调用 shortestPath 至多 100 次。
*/

#ifndef _GRAPH_SHORTEST_PATH_FLOYD_LEETCODE2642_H_
#define _GRAPH_SHORTEST_PATH_FLOYD_LEETCODE2642_H_

class Graph2642Floyd
{
    int n;
    vector<vector<int>> distance;
    void floyd()
    {
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                if (i == k || distance[i][k] >= INT_MAX / 2)
                {
                    continue;
                }
                for (int j = 0; j < n; ++j)
                {
                    if (j == k || distance[k][j] >= INT_MAX / 2)
                    {
                        continue;
                    }
                    distance[i][j] =
                        min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }
    int dijkstra(int node1, int node2)
    {
        vector<int> distan(n, INT_MAX / 2);
        distan[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.emplace(0, node1);
        while (!pq.empty())
        {
            auto [dis, idx] = pq.top();
            pq.pop();
            if (distan[idx] < dis)
            {
                continue;
            }

            for (auto [y, cos] : graph[idx])
            {
                if (distan[y] > dis + cos)
                {
                    distan[y] = dis + cos;
                    pq.emplace(distan[y], y);
                }
            }
        }

        return distan[node2];
    }
    unordered_map<int, vector<pair<int, int>>> graph;

public:
    Graph2642Floyd(int n, vector<vector<int>> &edges) : n(n)
    {
        distance = vector<vector<int>>(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; ++i)
        {
            distance[i][i] = 0;
        }
        for (auto edge : edges)
        {
            distance[edge[0]][edge[1]] = edge[2];
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }
        floyd();
    }

    void
    addEdge(vector<int> edge)
    {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
        if (distance[edge[0]][edge[1]] <= edge[2])
        {
            return;
        }
        else
        {
            distance[edge[0]][edge[1]] = edge[2];

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (distance[i][edge[0]] >= INT_MAX / 2)
                    {
                        continue;
                    }
                    if (distance[edge[1]][j] >= INT_MAX / 2)
                    {
                        continue;
                    }
                    distance[i][j] =
                        min(distance[i][j], distance[i][edge[0]] + edge[2] +
                                                distance[edge[1]][j]);
                }
            }
        }
    }

    int shortestPath(int node1, int node2)
    {
        // int res = distance[node1][node2];
        int res = dijkstra(node1, node2);
        return res >= INT_MAX / 2 ? -1 : res;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

void test2642Floyd()
{
    vector<vector<int>> edges = {{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
    Graph2642Floyd *obj = new Graph2642Floyd(4, edges);
    cout << obj->shortestPath(3, 2) << endl;
    cout << obj->shortestPath(0, 3) << endl;
    obj->addEdge({1, 3, 4});
    cout << obj->shortestPath(0, 3) << endl;
}

#endif // _GRAPH_SHORTEST_PATH_FLOYD_LEETCODE2642_H_