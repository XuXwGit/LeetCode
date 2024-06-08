/*
42. 接雨水
已解答
困难
相关标签
相关企业
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9


提示：

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 10^5
*/

#ifndef _LEETCODE_MONOTONIC_STACK_LEETCODE42_H_
#define _LEETCODE_MONOTONIC_STACK_LEETCODE42_H_

class Solution42
{
public:
    int trap(vector<int> &height)
    {
        int res = 0;
        stack<int> stac;
        for (int i = 0; i < height.size(); ++i)
        {
            while (!stac.empty() && height[stac.top()] <= height[i])
            {
                int bootom = height[stac.top()];
                stac.pop();
                if (!stac.empty())
                {
                    int h = min(height[stac.top()], height[i]) - bootom;
                    int len = i - (stac.top() + 1);
                    res += len * h;
                }
            }

            stac.push(i);
        }

        return res;
    }
};

void test42()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution42 solution42;
    cout << solution42.trap(height) << endl;
    height = {4, 2, 0, 3, 2, 5};
    cout << solution42.trap(height) << endl;
}

#endif // _LEETCODE_MONOTONIC_STACK_LEETCODE42_H_