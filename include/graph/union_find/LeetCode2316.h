/*
2316. 统计无向图中无法互相到达点对数
已解答
中等
相关标签
相关企业
提示
给你一个整数 n ，表示一张 无向图 中有 n 个节点，编号为 0 到 n - 1 。同时给你一个二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条 无向 边。

请你返回 无法互相到达 的不同 点对数目 。



示例 1：



输入：n = 3, edges = [[0,1],[0,2],[1,2]]
输出：0
解释：所有点都能互相到达，意味着没有点对无法互相到达，所以我们返回 0 。
示例 2：



输入：n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
输出：14
解释：总共有 14 个点对互相无法到达：
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]]
所以我们返回 14 。

*/

#ifndef _LEETCODE_GRAPH_UNION_FIND_2316_H_
#define _LEETCODE_GRAPH_UNION_FIND_2316_H_

class Solution2316
{
private:
    int num;
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
        if (find(x) != find(y))
        {
            parents[find(x)] = find(y);
            counts[find(y)] += counts[find(x)];
        }
    }

public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        num = n;
        parents = vector<int>(n, 0);
        counts = vector<int>(n, 1);
        for (int i = 0; i < n; ++i)
        {
            parents[i] = i;
        }

        for (auto x : edges)
        {
            merge(x[0], x[1]);
        }

        unordered_map<int, int> maps;
        for (int i = 0; i < num; ++i)
        {
            maps[find(i)] = counts[find(i)];
        }

        vector<int> temps;
        for (auto x : maps)
        {
            temps.push_back(x.second);
        }

        long long res = 0;
        int curs = num;
        for (int i = 0; i < temps.size(); ++i)
        {
            curs -= temps[i];
            res += temps[i] * curs;
        }

        return res;
    }
};

void test2316()
{
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};
    Solution2316 solution2316;
    cout << solution2316.countPairs(n, edges) << endl;

    n = 7;
    edges = {{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
    cout << solution2316.countPairs(n, edges) << endl;
}

#endif // !_LEETCODE_GRAPH_UNION_FIND_2316_H_