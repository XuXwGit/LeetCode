/*
207. 课程表
已解答
中等
相关标签
相关企业
提示
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
*/

#ifndef __LEETCODE_207_H__
#define __LEETCODE_207_H__

class Solution207
{
private:
    struct course
    {
        int nums_pre = 0;
        vector<int> nexts;
    };

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, course> courses;
        for (auto x : prerequisites)
        {
            courses[x[0]].nums_pre++;
            courses[x[1]].nexts.push_back(x[0]);
        }

        queue<int> zero_degree_nodes;
        for (auto [id, x] : courses)
        {
            if (x.nums_pre == 0)
            {
                zero_degree_nodes.push(id);
            }
        }

        while (!zero_degree_nodes.empty())
        {
            int curr = zero_degree_nodes.front();
            zero_degree_nodes.pop();
            for (auto next : courses[curr].nexts)
            {
                courses[next].nums_pre--;
                if (courses[next].nums_pre == 0)
                {
                    zero_degree_nodes.push(next);
                }
            }
            courses.erase(curr);
        }

        return courses.empty();
    }
};

void test207()
{
    Solution207 solution207;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    cout << (solution207.canFinish(2, prerequisites) ? "true" : "false") << endl;
}

#endif // __LEETCODE_207_H__