/*
2406. 将区间分为最少组数
中等
相关标签
相关企业
提示
给你一个二维整数数组 intervals ，其中 intervals[i] = [lefti, righti] 表示 闭 区间 [lefti, righti] 。

你需要将 intervals 划分为一个或者多个区间 组 ，每个区间 只 属于一个组，且同一个组中任意两个区间 不相交 。

请你返回 最少 需要划分成多少个组。

如果两个区间覆盖的范围有重叠（即至少有一个公共数字），那么我们称这两个区间是 相交 的。比方说区间 [1, 5] 和 [5, 8] 相交。



示例 1：

输入：intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
输出：3
解释：我们可以将区间划分为如下的区间组：
- 第 1 组：[1, 5] ，[6, 8] 。
- 第 2 组：[2, 3] ，[5, 10] 。
- 第 3 组：[1, 10] 。
可以证明无法将区间划分为少于 3 个组。
示例 2：

输入：intervals = [[1,3],[5,6],[8,10],[11,13]]
输出：1
解释：所有区间互不相交，所以我们可以把它们全部放在一个组内。


提示：

1 <= intervals.length <= 10^5
intervals[i].length == 2
1 <= lefti <= righti <= 10^6
*/

#ifndef _GREEDY_LEETCODE2406_H_
#define _GREEDY_LEETCODE2406_H_

class Solution2406
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        // 区间按照左端点排序
        sort(intervals.begin(), intervals.end(), [](vector<int> &le, vector<int> &rh)
             {
            if(le[0] == rh[0]){
                return le[1] < rh[1];
            }else{
                return le[0] < rh[0];
            } });

        // min_max_rh存放组的右端点
        priority_queue<int, vector<int>, greater<int>> min_max_rh;
        min_max_rh.push(intervals[0][1]);
        // 从前往后处理每个区间
        for (int i = 1; i < intervals.size(); ++i)
        {
            // 判断能否放到最小组中
            if (min_max_rh.top() < intervals[i][0])
            {
                min_max_rh.pop();
                min_max_rh.push(intervals[i][1]);
            }
            else
            {
                // create new group
                min_max_rh.push(intervals[i][1]);
            }
        }

        return min_max_rh.size();
    }
};

void test2406()
{
    Solution2406 solution;
    vector<vector<int>> intervals = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
    cout << solution.minGroups(intervals) << endl;
    vector<vector<int>> intervals2 = {{1, 3}, {5, 6}, {8, 10}, {11, 13}};
    cout << solution.minGroups(intervals2) << endl;
}

#endif // !_GREEDY_LEETCODE2406_H_