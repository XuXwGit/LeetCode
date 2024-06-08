/*
84. 柱状图中最大的矩形
已解答
困难
相关标签
相关企业
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。



示例 1:



输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
示例 2：



输入： heights = [2,4]
输出： 4


提示：

1 <= heights.length <=10^5
0 <= heights[i] <= 10^4
*/

#ifndef _LEETCODE_STACK_MONOTONIC_STACK_LEETCODE84_H_
#define _LEETCODE_STACK_MONOTONIC_STACK_LEETCODE84_H_

class Solution84
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    heights.insert(heights.begin(), 0);
    heights.push_back(0);

    int n = heights.size();
    int res = 0;
    vector<int> stac;
    for (int i = 0; i < n; ++i)
    {
      while (!stac.empty() && heights[stac.back()] > heights[i])
      {
        int curr = stac.back();
        stac.pop_back();
        res = max(res, heights[curr] * (i - stac.back() - 1));
      }
      stac.push_back(i);
    }

    return res;
  }
};

void test84()
{
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  Solution84 solution84;
  cout << solution84.largestRectangleArea(heights) << endl;
  heights = {2, 1, 2};
  cout << solution84.largestRectangleArea(heights) << endl;
}

#endif // !_LEETCODE_STACK_MONOTONIC_STACK_LEETCODE84_H_