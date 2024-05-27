/*
435. 无重叠区间
已解答
中等
相关标签
相关企业
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。



示例 1:

输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: intervals = [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: intervals = [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。


提示:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104
*/

#ifndef _GREEDY_LEETCODE435_H_
#define _GREEDY_LEETCODE435_H_

class Solution435
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &le, vector<int> &rh)
             {
               if(le[1] != rh[1]) return le[1] < rh[1];
               else return le[0] < rh[0]; });

        int n = intervals.size();
        int res = 0;
        int curr = intervals[0][1];
        for (int i = 1; i < n; ++i)
        {
            if (curr > intervals[i][0] && curr <= intervals[i][1])
            {
                res++;
            }
            else
            {
                curr = intervals[i][1];
            }
        }

        return res;
    }
};

void test435()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    Solution435 solution435;
    cout << solution435.eraseOverlapIntervals(intervals) << endl;
}

#endif // !_GREEDY_LEETCODE435_H_