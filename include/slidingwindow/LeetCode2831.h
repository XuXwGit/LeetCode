/*
2831. 找出最长等值子数组
尝试过
中等
相关标签
相关企业
提示
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

如果子数组中所有元素都相等，则认为子数组是一个 等值子数组 。注意，空数组是 等值子数组 。

从 nums 中删除最多 k 个元素后，返回可能的最长等值子数组的长度。

子数组 是数组中一个连续且可能为空的元素序列。



示例 1：

输入：nums = [1,3,2,3,1,3], k = 3
输出：3
解释：最优的方案是删除下标 2 和下标 4 的元素。
删除后，nums 等于 [1, 3, 3, 3] 。
最长等值子数组从 i = 1 开始到 j = 3 结束，长度等于 3 。
可以证明无法创建更长的等值子数组。
*/

#ifndef _LEETCODE_SLIDINGWINDOW_H_
#define _LEETCODE_SLIDINGWINDOW_H_

class Solution2831
{
public:
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        unordered_map<int, vector<int>> maps;
        for (int i = 0; i < nums.size(); ++i)
        {
            maps[nums[i]].push_back(i);
        }

        int res = 1;
        for (auto [x, pos] : maps)
        {
            int left = 0;
            int right = pos.size() - 1;
            int need = pos[right] - pos[left] + 1 - pos.size();
            int count = pos.size();
            while (need > k)
            {
                if (pos[left + 1] - pos[left] > pos[right] - pos[right - 1])
                {
                    left++;
                }
                else
                {
                    right--;
                }
                count--;
                need = pos[right] - pos[left] + 1 - count;
            }
            res = max(res, count);
        }

        return res;
    }
};

void test2831()
{
    Solution2831 solution2831;
    vector<int> nums = {1, 3, 2, 3, 1, 3};
    int k = 3;
    cout << solution2831.longestEqualSubarray(nums, k) << endl;

    // [4,2,7,2,1,7,2]
    // k = 1
    nums = {4, 2, 7, 2, 1, 7, 2};
    k = 1;
    cout << solution2831.longestEqualSubarray(nums, k) << endl;

    // [9,4,9,6,7,4,6,2,8,10,6,6,1,10,6]
    // k = 4
    nums = {9, 4, 9, 6, 7, 4, 6, 2, 8, 10, 6, 6, 1, 10, 6};
    k = 4;
    cout << solution2831.longestEqualSubarray(nums, k) << endl;
}

#endif // !_LEETCODE_SLIDINGWINDOW_H_