/*
1203. 项目管理
困难
相关标签
相关企业
提示
有 n 个项目，每个项目或者不属于任何小组，或者属于 m 个小组之一。group[i] 表示第 i 个项目所属的小组，如果第 i 个项目不属于任何小组，则 group[i] 等于 -1。项目和小组都是从零开始编号的。可能存在小组不负责任何项目，即没有任何项目属于这个小组。

请你帮忙按要求安排这些项目的进度，并返回排序后的项目列表：

同一小组的项目，排序后在列表中彼此相邻。
项目之间存在一定的依赖关系，我们用一个列表 beforeItems 来表示，其中 beforeItems[i] 表示在进行第 i 个项目前（位于第 i 个项目左侧）应该完成的所有项目。
如果存在多个解决方案，只需要返回其中任意一个即可。如果没有合适的解决方案，就请返回一个 空列表 。



示例 1：



输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
输出：[6,3,4,1,5,2,0,7]
示例 2：

输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
输出：[]
解释：与示例 1 大致相同，但是在排序后的列表中，4 必须放在 6 的前面。


提示：

1 <= m <= n <= 3 * 104
group.length == beforeItems.length == n
-1 <= group[i] <= m - 1
0 <= beforeItems[i].length <= n - 1
0 <= beforeItems[i][j] <= n - 1
i != beforeItems[i][j]
beforeItems[i] 不含重复元素
*/

#ifndef _LEETCODE_GRAPH_TOPOLOGICAL_LEETCODE1203_H_
#define _LEETCODE_GRAPH_TOPOLOGICAL_LEETCODE1203_H_

class Solution1203
{
private:
    bool topologicalSort(vector<int> &res, unordered_set<int> &nodes, unordered_map<int, set<int>> &graph)
    {
        unordered_map<int, int> indegrees;
        for (auto [x, next] : graph)
        {
            for (int y : next)
            {
                indegrees[y]++;
            }
        }

        queue<int> zeros;
        for (auto [x, count] : indegrees)
        {
            if (count == 0)
            {
                zeros.push(x);
            }
        }

        for (int x : nodes)
        {
            if (!indegrees.count(x))
            {
                zeros.push(x);
            }
        }

        vector<int> temp;
        while (!zeros.empty())
        {
            int curr = zeros.front();
            for (auto x : graph[curr])
            {
                if (--indegrees[x] == 0)
                {
                    zeros.push(x);
                }
            }
            temp.push_back(curr);
            zeros.pop();
        }

        if (temp.size() != nodes.size())
        {
            return false;
        }
        else
        {
            res.insert(res.end(), temp.begin(), temp.end());
        }

        return true;
    }

public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {
        unordered_map<int, int> groups;
        unordered_set<int> GroupSet;
        unordered_map<int, unordered_set<int>> ItemSets;
        for (int i = 0; i < n; ++i)
        {
            if (group[i] >= 0)
            {
                groups[i] = group[i];
            }
            else
            {
                groups[i] = m;
                m++;
            }
            GroupSet.insert(groups[i]);
            ItemSets[groups[i]].insert(i);
        }

        unordered_map<int, set<int>> GroupGraph;
        unordered_map<int, unordered_map<int, set<int>>> ItemGroups;
        for (int i = 0; i < n; ++i)
        {
            for (auto bf : beforeItems[i])
            {
                if (groups[i] == groups[bf])
                {
                    ItemGroups[groups[i]][bf].insert(i);
                }
                else
                {
                    GroupGraph[groups[bf]].insert(groups[i]);
                }
            }
        }

        vector<int> res_group;
        if (!topologicalSort(res_group, GroupSet, GroupGraph))
        {
            return vector<int>{};
        }

        vector<int> res;
        for (int x : res_group)
        {
            if (!(topologicalSort(res, ItemSets[x], ItemGroups[x])))
            {
                return vector<int>{};
            }
        }

        return res;
    }
};
void test1203()
{
    Solution1203 solution1203;
    int n = 8, m = 2;
    vector<int> group = {-1, -1, 1, 0, 0, 1, 0, -1};
    vector<vector<int>> beforeItems = {{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}};
    vector<int> res = solution1203.sortItems(n, m, group, beforeItems);
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    // [2,0,-1,3,0]
    // [[2,1,3],[2,4],[],[],[]]
    // n = 5, m = 5;
    group = {2, 0, -1, 3, 0};
    beforeItems = {{2, 1, 3}, {2, 4}, {}, {}, {}};
    n = 5, m = 5;
    res = solution1203.sortItems(n, m, group, beforeItems);
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

#endif // !_LEETCODE_GRAPH_TOPOLOGICAL_LEETCODE1203_H_