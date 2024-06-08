/*
LCR 113. 课程表 II
已解答
中等
相关标签
相关企业
现在总共有 numCourses 门课需要选，记为 0 到 numCourses-1。

给定一个数组 prerequisites ，它的每一个元素 prerequisites[i] 表示两门课程之间的先修顺序。 例如 prerequisites[i] = [ai, bi] 表示想要学习课程 ai ，需要先完成课程 bi 。

请根据给出的总课程数  numCourses 和表示先修顺序的 prerequisites 得出一个可行的修课序列。

可能会有多个正确的顺序，只要任意返回一种就可以了。如果不可能完成所有课程，返回一个空数组。



示例 1:

输入: numCourses = 2, prerequisites = [[1,0]]
输出: [0,1]
解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
示例 2:

输入: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
输出: [0,1,2,3] or [0,2,1,3]
解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
 因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
示例 3:

输入: numCourses = 1, prerequisites = []
输出: [0]
解释: 总共 1 门课，直接修第一门课就可。


提示:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
prerequisites 中不存在重复元素
*/

#ifndef _LEETCODE_GRAPH_BFS_TOPOLOGICAL_LEETCODE113_H_
#define _LEETCODE_GRAPH_BFS_TOPOLOGICAL_LEETCODE113_H_

class SolutionLCR113
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(n, 0);
        unordered_map<int, vector<int>> graph;
        for (auto edge : prerequisites)
        {
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> zeros;
        for (int i = 0; i < n; ++i)
        {
            if (indegree[i] == 0)
            {
                zeros.push(i);
            }
        }

        vector<int> res;
        while (!zeros.empty())
        {
            int curr = zeros.front();
            zeros.pop();

            for (int next : graph[curr])
            {
                if (--indegree[next] == 0)
                {
                    zeros.push(next);
                }
            }

            res.push_back(curr);
        }

        return res.size() == n ? res : vector<int>{};
    }
};

void testLCR113()
{
    SolutionLCR113 solutionLCR113;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    vector<int> res = solutionLCR113.findOrder(numCourses, prerequisites);
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

#endif // !_LEETCODE_GRAPH_BFS_TOPOLOGICAL_LEETCODE113_H_