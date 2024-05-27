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
*/

#ifndef _GRAPH_UNION_FIND_SET_LEETCODE924_H_
#define _GRAPH_UNION_FIND_SET_LEETCODE924_H_

class Solution924UFS
{
private:
    vector<int> parents;
    vector<int> counts;
    int find(int x)
    {
        if (parents[x] != x)
        {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }
    void merge(int x, int y)
    {
        int p_x = find(x);
        int p_y = find(y);
        if (p_x != p_y)
        {
            parents[p_x] = p_y;
            counts[p_y] += counts[p_x];
        }
    }

public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
    {
        int n = graph.size();

        parents = vector<int>(n, 0);
        counts = vector<int>(n, 1);
        for (int i = 0; i < n; ++i)
        {
            parents[i] = i;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (graph[i][j] == 1)
                {
                    merge(i, j);
                }
            }
        }

        // key: father node
        // value: <initial node>
        map<int, vector<int>> maps;
        for (int ini : initial)
        {
            maps[find(ini)].push_back(ini);
        }

        sort(initial.begin(), initial.end());
        int res = initial[0];

        int max_saved = 0;
        for (auto x : maps)
        {
            if (x.second.size() == 1)
            {
                if (counts[find(x.first)] > max_saved || (counts[find(x.first)] == max_saved && res > x.second[0]))
                {
                    max_saved = counts[find(x.first)];
                    res = x.second[0];
                }
            }
        }

        return res;
    }
};

void test924UFS()
{
    // [[1,0,0],[0,1,0],[0,0,1]]
    // [0,2]
    vector<vector<int>> graph = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    vector<int> initial = {0, 2};
    cout << Solution924UFS().minMalwareSpread(graph, initial) << endl;

    // [[1,1,1],[1,1,1],[1,1,1]]
    // [1,2]
    graph = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    initial = {1, 2};
    cout << Solution924UFS().minMalwareSpread(graph, initial) << endl;
}

#endif // !_GRAPH_UNION_FIND_SET_LEETCODE924_H_