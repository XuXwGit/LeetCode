/*
503. 下一个更大元素 II
已解答
中等
相关标签
相关企业
给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素 。

数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1 。



示例 1:

输入: nums = [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数；
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
示例 2:

输入: nums = [1,2,3,4,3]
输出: [2,3,4,-1,4]


提示:

1 <= nums.length <= 10^4
-109 <= nums[i] <= 10^9
*/

#ifndef _LEETCODE_STACK_MONOTONIC_STACK_LEETCODE503_H_
#define _LEETCODE_STACK_MONOTONIC_STACK_LEETCODE503_H_

class Solution503
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> newnums = nums;
        newnums.insert(newnums.begin(), nums.begin(), nums.end());

        vector<int> st;
        vector<int> res(nums.size(), -1);
        for (int i = newnums.size() - 1; i >= 0; --i)
        {
            while (!st.empty() && newnums[st.back()] <= newnums[i])
            {
                st.pop_back();
            }
            if (i < nums.size())
            {
                res[i] = st.empty() ? -1 : newnums[st.back()];
            }
            st.push_back(i);
        }

        return res;
    }
};

void test503()
{
    vector<int> nums = {1, 2, 1};
    Solution503 solution503;
    vector<int> res = solution503.nextGreaterElements(nums);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

#endif // !_LEETCODE_STACK_MONOTONIC_STACK_LEETCODE503_H_