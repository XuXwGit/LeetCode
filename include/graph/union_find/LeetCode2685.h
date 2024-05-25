/*
2685. 统计完全连通分量的数量
已解答
中等
相关标签
相关企业
提示
给你一个整数 n 。现有一个包含 n 个顶点的 无向 图，顶点按从 0 到 n - 1 编号。给你一个二维整数数组 edges 其中 edges[i] = [ai, bi] 表示顶点 ai 和 bi 之间存在一条 无向 边。

返回图中 完全连通分量 的数量。

如果在子图中任意两个顶点之间都存在路径，并且子图中没有任何一个顶点与子图外部的顶点共享边，则称其为 连通分量 。

如果连通分量中每对节点之间都存在一条边，则称其为 完全连通分量 。



示例 1：



输入：n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
输出：3
解释：如上图所示，可以看到此图所有分量都是完全连通分量。
示例 2：



输入：n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
输出：1
解释：包含节点 0、1 和 2 的分量是完全连通分量，因为每对节点之间都存在一条边。
包含节点 3 、4 和 5 的分量不是完全连通分量，因为节点 4 和 5 之间不存在边。
因此，在图中完全连接分量的数量是 1 。
*/

#ifndef _LEETCODE_GRAPH_UNION_FIND_2685_H_
#define _LEETCODE_GRAPH_UNION_FIND_2685_H_

class Solution2685
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
        int px = find(x);
        int py = find(y);
        if (px != py)
        {
            parents[px] = py;
            counts[py] += counts[px];
        }
        counts[py]++;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        parents = vector<int>(n);
        counts = vector<int>(n, 0);
        for (int i = 0; i < n; ++i)
        {
            parents[i] = i;
        }

        for (auto x : edges)
        {
            merge(x[0], x[1]);
        }

        unordered_map<int, pair<int, int>> maps;
        for (int i = 0; i < n; ++i)
        {
            maps[find(i)].first++;
            maps[find(i)].second = counts[find(i)];
        }

        int res = 0;
        for (auto [x, y] : maps)
        {
            if (y.first * (y.first - 1) == 2 * y.second)
            {
                res++;
            }
        }
        return res;
    }
};

void test2685()
{
    Solution2685 solution2685;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    cout << solution2685.countCompleteComponents(6, edges) << endl;
    edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};
    cout << solution2685.countCompleteComponents(6, edges) << endl;
    edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}, {4, 5}};
    cout << solution2685.countCompleteComponents(6, edges) << endl;
}

#endif // !_LEETCODE_GRAPH_UNION_FIND_2685_H_