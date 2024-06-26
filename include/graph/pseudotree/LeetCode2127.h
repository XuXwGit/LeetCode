/*
2127. 参加会议的最多员工数
困难
相关标签
相关企业
提示
一个公司准备组织一场会议，邀请名单上有 n 位员工。公司准备了一张 圆形 的桌子，可以坐下 任意数目 的员工。

员工编号为 0 到 n - 1 。每位员工都有一位 喜欢 的员工，每位员工 当且仅当 他被安排在喜欢员工的旁边，他才会参加会议。每位员工喜欢的员工 不会 是他自己。

给你一个下标从 0 开始的整数数组 favorite ，其中 favorite[i] 表示第 i 位员工喜欢的员工。请你返回参加会议的 最多员工数目 。



示例 1：



输入：favorite = [2,2,1,2]
输出：3
解释：
上图展示了公司邀请员工 0，1 和 2 参加会议以及他们在圆桌上的座位。
没办法邀请所有员工参与会议，因为员工 2 没办法同时坐在 0，1 和 3 员工的旁边。
注意，公司也可以邀请员工 1，2 和 3 参加会议。
所以最多参加会议的员工数目为 3 。
示例 2：

输入：favorite = [1,2,0]
输出：3
解释：
每个员工都至少是另一个员工喜欢的员工。所以公司邀请他们所有人参加会议的前提是所有人都参加了会议。
座位安排同图 1 所示：
- 员工 0 坐在员工 2 和 1 之间。
- 员工 1 坐在员工 0 和 2 之间。
- 员工 2 坐在员工 1 和 0 之间。
参与会议的最多员工数目为 3 。
示例 3：



输入：favorite = [3,0,1,4,1]
输出：4
解释：
上图展示了公司可以邀请员工 0，1，3 和 4 参加会议以及他们在圆桌上的座位。
员工 2 无法参加，因为他喜欢的员工 1 旁边的座位已经被占领了。
所以公司只能不邀请员工 2 。
参加会议的最多员工数目为 4 。

*/

#ifndef _GRAPH_PSEUDOTREE_LEETCODE2127_H_
#define _GRAPH_PSEUDOTREE_LEETCODE2127_H_

class Solution2127
{
public:
    int maximumInvitations(vector<int> &favorite)
    {
        int n = favorite.size();

        vector<int> indegrees(n, 0);

        for (int x : favorite)
        {
            indegrees[x]++;
        }

        vector<int> visited(n, false);

        queue<int> zeros;
        for (int i = 0; i < n; ++i)
        {
            if (indegrees[i] == 0)
            {
                zeros.push(i);
            }
        }

        vector<int> precounts(n, 0);
        while (!zeros.empty())
        {
            int curr = zeros.front();
            indegrees[favorite[curr]]--;
            precounts[favorite[curr]] = max(precounts[favorite[curr]], precounts[curr] + 1);
            if (indegrees[favorite[curr]] == 0)
            {
                zeros.push(favorite[curr]);
            }
            visited[curr] = true;
            zeros.pop();
        }

        int max_ring = 0;
        int sum_chain = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                int curr = i;
                vector<int> cycle;
                while (favorite[curr] != i)
                {
                    visited[curr] = true;
                    cycle.push_back(curr);
                    curr = favorite[curr];
                }
                visited[curr] = true;
                cycle.push_back(curr);

                if ((int)cycle.size() == 2)
                {
                    sum_chain += (int)cycle.size() + precounts[i] + precounts[favorite[i]];
                }
                else
                {
                    max_ring = max(max_ring, (int)cycle.size());
                }
            }
        }

        return max(max_ring, sum_chain);
    }
};
void test2127()
{
    Solution2127 solution2127;

    vector<int> favorite = {2, 2, 1, 2};
    int res = solution2127.maximumInvitations(favorite);
    cout << res << endl;

    // [1,0,3,2,5,6,7,4,9,8,11,10,11,12,10]
    favorite = {1, 0, 3, 2, 5, 6, 7, 4, 9, 8, 11, 10, 11, 12, 10};
    res = solution2127.maximumInvitations(favorite);
    cout << res << endl;
}

#endif // !_GRAPH_PSEUDOTREE_LEETCODE2127_H_