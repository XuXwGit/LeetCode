/*
924. 尽量减少恶意软件的传播
已解答
困难
相关标签
相关企业
给出了一个由 n 个节点组成的网络，用 n × n 个邻接矩阵图 graph 表示。在节点网络中，当 graph[i][j] = 1 时，表示节点 i 能够直接连接到另一个节点 j。

一些节点 initial 最初被恶意软件感染。只要两个节点直接连接，且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。

假设 M(initial) 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。

如果从 initial 中移除某一节点能够最小化 M(initial)， 返回该节点。如果有多个节点满足条件，就返回索引最小的节点。

请注意，如果某个节点已从受感染节点的列表 initial 中删除，它以后仍有可能因恶意软件传播而受到感染。



示例 1：

输入：graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
输出：0
示例 2：

输入：graph = [[1,0,0],[0,1,0],[0,0,1]], initial = [0,2]
输出：0
示例 3：

输入：graph = [[1,1,1],[1,1,1],[1,1,1]], initial = [1,2]
输出：1


提示：

n == graph.length
n == graph[i].length
2 <= n <= 300
graph[i][j] == 0 或 1.
graph[i][j] == graph[j][i]
graph[i][i] == 1
1 <= initial.length <= n
0 <= initial[i] <= n - 1
initial 中所有整数均不重复
*/

#ifndef _GRAPH_BFS_LEETCODE924_H_
#define _GRAPH_BFS_LEETCODE924_H_

class Solution924BFS
{
private:
    int bfs(int remove, vector<bool> &visited, unordered_map<int, vector<int>> &graph, vector<int> &initial)
    {
        int count = 0;
        queue<int> pq;
        for (int ini : initial)
        {
            if (ini != remove)
            {
                pq.push(ini);
                count++;
                visited[ini] = true;
            }
        }

        while (!pq.empty())
        {
            for (int j : graph[pq.front()])
            {
                if (!visited[j])
                {
                    pq.push(j);
                    count++;
                    visited[j] = true;
                }
            }

            pq.pop();
        }

        return count;
    }

public:
    int minMalwareSpread(vector<vector<int>> &edges, vector<int> &initial)
    {
        unordered_map<int, vector<int>> graph;
        int n = edges.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                if (edges[i][j] == 1)
                {
                    graph[i].push_back(j);
                }
            }
        }

        int res = 0;
        int sel = INT_MAX;
        sort(initial.begin(), initial.end());
        for (int i : initial)
        {
            vector<bool> visited(n, false);
            int temp = bfs(i, visited, graph, initial);
            if (temp < sel)
            {
                res = i;
                sel = temp;
            }
        }

        return res;
    }
};

void test924BFS()
{
    // [[1,0,0,0],[0,1,0,0],[0,0,1,1],[0,0,1,1]]
    // [3,1]
    vector<vector<int>> edges = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}};
    vector<int> initial = {3, 1};
    cout << Solution924BFS().minMalwareSpread(edges, initial) << endl;

    // [[1,0,0,0,1,0,0,0,0,0,1],[0,1,0,1,0,0,0,0,0,0,0],[0,0,1,0,0,0,0,1,0,0,0],[0,1,0,1,0,1,0,0,0,0,0],[1,0,0,0,1,0,0,0,0,0,0],[0,0,0,1,0,1,0,0,1,1,0],[0,0,0,0,0,0,1,1,0,0,0],[0,0,1,0,0,0,1,1,0,0,0],[0,0,0,0,0,1,0,0,1,0,0],[0,0,0,0,0,1,0,0,0,1,0],[1,0,0,0,0,0,0,0,0,0,1]]
    // [7,8,6,2,3]
    edges = {{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
             {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
             {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
             {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0},
             {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
             {0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
             {0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
             {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};
    initial = {7, 8, 6, 2, 3};
    cout << Solution924BFS().minMalwareSpread(edges, initial) << endl;
}

#endif