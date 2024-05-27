/*
LCR 074. 合并区间
已解答
中等
相关标签
相关企业
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。



示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。


提示：

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

*/

#ifndef _GREEDY_RANGES_LCR074_H_
#define _GREEDY_RANGES_LCR074_H_

class SolutionLCR074
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](vector<int> &le, vector<int> &rh)
             {
            if(le[1] == rh[1]){
                return le[0] < rh[0];
            }else{
                return le[1] < rh[1];
            } });

        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] > res.back()[1])
            {
                res.push_back(intervals[i]);
            }
            else if (intervals[i][0] >= res.back()[0])
            {
                res.back()[1] = intervals[i][1];
            }
            else
            {
                while (!res.empty() && res.back()[0] >= intervals[i][0])
                {
                    res.pop_back();
                }

                if (res.empty() || res.back()[1] < intervals[i][0])
                {
                    res.push_back(intervals[i]);
                }
                else
                {
                    res.back()[1] = intervals[i][1];
                }
            }
        }

        return res;
    }
};

void testLCR074()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    SolutionLCR074 solution;
    vector<vector<int>> res = solution.merge(intervals);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << "[" << res[i][0] << "," << res[i][1] << "]" << endl;
    }
}

#endif // !_GREEDY_RANGES_LCR074_H_