/*
210. 课程表 II
已解答
中等
相关标签
相关企业
提示
现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。

例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。
*/

#ifndef __LEETCODE_210_H__
#define __LEETCODE_210_H__

class Solution210
{
private:
    struct node
    {
        int num_pres = 0;
        vector<int> nexts;
    };

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, node> cours;
        for (auto x : prerequisites)
        {
            cours[x[0]].num_pres++;
            cours[x[1]].nexts.push_back(x[0]);
        }

        vector<int> res;
        queue<int> zeros;
        for (int i = 0; i < numCourses; ++i)
        {
            if (cours[i].num_pres == 0)
            {
                zeros.push(i);
            }
        }

        while (!zeros.empty())
        {
            int curr = zeros.front();
            zeros.pop();
            for (auto x : cours[curr].nexts)
            {
                cours[x].num_pres--;
                if (cours[x].num_pres == 0)
                {
                    zeros.push(x);
                }
            }
            cours.erase(curr);
            res.push_back(curr);
        }

        return res.size() == numCourses ? res : vector<int>();
    }
};

void test210()
{
    // 1
    // []
    int numCourses = 1;
    vector<vector<int>> prerequisites;

    Solution210 solution210;

    vector<int> res = solution210.findOrder(numCourses, prerequisites);
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;
}

#endif // __LEETCODE_210_H__