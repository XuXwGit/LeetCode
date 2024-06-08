/*
698. 划分为k个相等的子集
尝试过
中等
相关标签
相关企业
提示
给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。



示例 1：

输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
输出： True
说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
示例 2:

输入: nums = [1,2,3,4], k = 3
输出: false


提示：

1 <= k <= len(nums) <= 16
0 < nums[i] < 10000
每个元素的频率在 [1,4] 范围内
*/

#ifndef _LEETCODE_DYNAMIC_KNAPSACK_LEETCODE698_H_
#define _LEETCODE_DYNAMIC_KNAPSACK_LEETCODE698_H_

class Solution698
{
private:
    bool dfs(int i, vector<int> &nums, vector<int> &targets)
    {
        if (i == nums.size())
        {
            for (int x : targets)
            {
                if (x)
                {
                    return false;
                }
            }
            return true;
        }

        int k = targets.size();

        for (int j = 0; j < k; ++j)
        {
            if (targets[j] < nums[i])
            {
                continue;
            }
            if (j > 0 && targets[j] == targets[j - 1])
            {
                continue;
            }
            targets[j] -= nums[i];
            if (dfs(i + 1, nums, targets))
            {
                return true;
            }
            targets[j] += nums[i];
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sums = accumulate(nums.begin(), nums.end(), 0);
        int target = sums / k;
        if (k * target != sums)
        {
            return false;
        }

        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> targets(k, target);
        return dfs(0, nums, targets);
    }
};

void test698()
{
    Solution698 solution698;
    // [10,1,10,9,6,1,9,5,9,10,7,8,5,2,10,8]
    vector<int> nums = {10, 1, 10, 9, 6, 1, 9, 5, 9, 10, 7, 8, 5, 2, 10, 8};
    int k = 11;
    cout << (solution698.canPartitionKSubsets(nums, k) ? "true" : "false") << endl;
}

#endif // !_LEETCODE_DYNAMIC_KNAPSACK_LEETCODE698_H_