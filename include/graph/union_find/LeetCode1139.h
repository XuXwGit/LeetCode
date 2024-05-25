/*
1319. 连通网络的操作次数
已解答
中等
相关标签
相关企业
提示
用以太网线缆将 n 台计算机连接成一个网络，计算机的编号从 0 到 n-1。线缆用 connections 表示，其中 connections[i] = [a, b] 连接了计算机 a 和 b。

网络中的任何一台计算机都可以通过网络直接或者间接访问同一个网络中其他任意一台计算机。

给你这个计算机网络的初始布线 connections，你可以拔开任意两台直连计算机之间的线缆，并用它连接一对未直连的计算机。请你计算并返回使所有计算机都连通所需的最少操作次数。如果不可能，则返回 -1 。

示例 1：



输入：n = 4, connections = [[0,1],[0,2],[1,2]]
输出：1
解释：拔下计算机 1 和 2 之间的线缆，并将它插到计算机 1 和 3 上。
示例 2：



输入：n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
输出：2
示例 3：

输入：n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
输出：-1
解释：线缆数量不足。
示例 4：

输入：n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
输出：0

*/

#ifndef _LEETCODE_GRAPH_UNION_FIND_1319_H_
#define _LEETCODE_GRAPH_UNION_FIND_1319_H_

class Solution1319
{
private:
    vector<int> parents;
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
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
        {
            return -1;
        }

        parents = vector<int>(n);
        for (int i = 0; i < n; ++i)
        {
            parents[i] = i;
        }

        for (auto x : connections)
        {
            merge(x[0], x[1]);
        }

        set<int> groups;
        for (int i = 0; i < n; ++i)
        {
            groups.insert(find(i));
        }

        return groups.size() - 1;
    }
};

#endif // !_LEETCODE_GRAPH_UNION_FIND_1319_H_