/*
2360. 图中的最长环
已解答
困难
相关标签
相关企业
提示
给你一个 n 个节点的 有向图 ，节点编号为 0 到 n - 1 ，其中每个节点 至多 有一条出边。

图用一个大小为 n 下标从 0 开始的数组 edges 表示，节点 i 到节点 edges[i] 之间有一条有向边。如果节点 i 没有出边，那么 edges[i] == -1 。

请你返回图中的 最长 环，如果没有任何环，请返回 -1 。

一个环指的是起点和终点是 同一个 节点的路径。



示例 1：



输入：edges = [3,3,4,2,3]
输出去：3
解释：图中的最长环是：2 -> 4 -> 3 -> 2 。
这个环的长度为 3 ，所以返回 3 。
示例 2：



输入：edges = [2,-1,3,1]
输出：-1
解释：图中没有任何环。


提示：

n == edges.length
2 <= n <= 105
-1 <= edges[i] < n
edges[i] != i
*/

#ifndef _GRAPH_PSEUDOTREE_LEETCODE2360_H_
#define _GRAPH_PSEUDOTREE_LEETCODE2360_H_

class Solution2360
{
public:
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();

        vector<int> indegrees(n, 0);

        for (int x : edges)
        {
            if (x >= 0)
            {
                indegrees[x]++;
            }
        }

        queue<int> zeros;
        for (int i = 0; i < n; ++i)
        {
            if (indegrees[i] == 0)
            {
                zeros.push(i);
            }
        }

        while (!zeros.empty())
        {
            int curr = zeros.front();
            int next = edges[curr];
            if (next >= 0)
            {
                if (--indegrees[next] == 0)
                {
                    zeros.push(next);
                }
            }
            zeros.pop();
        }

        int maxLen = -1;
        for (int i = 0; i < n; ++i)
        {
            if (indegrees[i] == 0)
            {
                continue;
            }

            int curr = i;
            int count = 0;
            while (edges[curr] != i)
            {
                count++;
                indegrees[curr] = 0;
                curr = edges[curr];
            }
            count++;
            indegrees[curr] = 0;

            maxLen = max(maxLen, count);
        }

        return maxLen;
    }
};

void test2360()
{
    vector<int> edges = {3, 3, 4, 2, 3};
    Solution2360 solution2360;
    int res = solution2360.longestCycle(edges);
    cout << res << endl;
}

#endif // _GRAPH_PSEUDOTREE_LEETCODE2360_H_