/*
1462. 课程表 IV
已解答
中等
相关标签
相关企业
提示
你总共需要上 numCourses 门课，课程编号依次为 0 到 numCourses-1 。你会得到一个数组 prerequisite ，其中 prerequisites[i] = [ai, bi] 表示如果你想选 bi 课程，你 必须 先选 ai 课程。

有的课会有直接的先修课程，比如如果想上课程 1 ，你必须先上课程 0 ，那么会以 [0,1] 数对的形式给出先修课程数对。
先决条件也可以是 间接 的。如果课程 a 是课程 b 的先决条件，课程 b 是课程 c 的先决条件，那么课程 a 就是课程 c 的先决条件。

你也得到一个数组 queries ，其中 queries[j] = [uj, vj]。对于第 j 个查询，您应该回答课程 uj 是否是课程 vj 的先决条件。

返回一个布尔数组 answer ，其中 answer[j] 是第 j 个查询的答案。



示例 1：



输入：numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
输出：[false,true]
解释：课程 0 不是课程 1 的先修课程，但课程 1 是课程 0 的先修课程。
示例 2：

输入：numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
输出：[false,false]
解释：没有先修课程对，所以每门课程之间是独立的。
示例 3：



输入：numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
输出：[true,true]


提示：

2 <= numCourses <= 100
0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
prerequisites[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
每一对 [ai, bi] 都 不同
先修课程图中没有环。
1 <= queries.length <= 10^4
0 <= ui, vi <= n - 1
ui != vi
*/

#ifndef _LEETCODE_GRAPH_TOPOLOGICAL_LEETCODE1462_H_
#define _LEETCODE_GRAPH_TOPOLOGICAL_LEETCODE1462_H_

class Solution1462
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        // build graph
        unordered_map<int, vector<int>> graph;
        vector<int> indegrees(numCourses, 0);
        vector<vector<bool>> visited(numCourses, vector<bool>(numCourses, false));
        for (auto edge : prerequisites)
        {
            graph[edge[0]].push_back(edge[1]);
            indegrees[edge[1]]++;
            visited[edge[0]][edge[1]] = true;
        }

        // bfs
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegrees[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int curr = q.front();
            for (int next : graph[curr])
            {
                if (--indegrees[next] == 0)
                {
                    q.push(next);
                }
            }
            for (int i = 0; i < numCourses; ++i)
            {
                for (int next : graph[curr])
                {
                    visited[i][next] = visited[i][next] || visited[i][curr];
                }
            }
            q.pop();
        }

        vector<bool> res;
        for (auto query : queries)
        {
            res.push_back(visited[query[0]][query[1]]);
        }
        return res;
    }
};

void test1462()
{
    vector<vector<int>> prerequisites = {{1, 0}};
    vector<vector<int>> queries = {{0, 1}, {1, 0}};
    Solution1462 solution;
    vector<bool> res = solution.checkIfPrerequisite(2, prerequisites, queries);
    for (bool b : res)
    {
        cout << b << " ";
    }
    cout << endl;
}

#endif // !_LEETCODE_GRAPH_TOPOLOGICAL_LEETCODE1462_H_