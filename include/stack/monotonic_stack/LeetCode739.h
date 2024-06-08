/*
739. 每日温度
已解答
中等
相关标签
相关企业
提示
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。



示例 1:

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
示例 2:

输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]
示例 3:

输入: temperatures = [30,60,90]
输出: [1,1,0]


提示：

1 <= temperatures.length <= 10^5
30 <= temperatures[i] <= 100
*/

#ifndef _LEETCODE_STACK_MONOTONIC_STACK_LEETCODE739_H_
#define _LEETCODE_STACK_MONOTONIC_STACK_LEETCODE739_H_

class Solution739
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> res(n, 0);

        vector<int> stac;
        for (int i = 0; i < n; ++i)
        {
            while (!stac.empty() && temperatures[stac.back()] < temperatures[i])
            {
                res[stac.back()] = i - stac.back();
                stac.pop_back();
            }
            stac.push_back(i);
        }

        return res;
    }
};

void test739()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution739 solution739;
    vector<int> res = solution739.dailyTemperatures(temperatures);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

#endif // !_LEETCODE_STACK_MONOTONIC_STACK_LEETCODE739_H_