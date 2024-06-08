/*
416. 分割等和子集
已解答
中等
相关标签
相关企业
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。



示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：

输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。


提示：

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

#ifndef _LEETCODE_DYNAMIC_KNAPSACK_LEETCODE416_H_
#define _LEETCODE_DYNAMIC_KNAPSACK_LEETCODE416_H_

class Solution416
{
private:
    bool dfs(int i, vector<int> &nums, int target)
    {
        if (i == nums.size())
        {
            return target == 0 ? true : false;
        }

        if (target == 0)
        {
            mem[i][target] = true;
            return mem[i][target];
        }
        else if (target < 0)
        {
            mem[i][target] = false;
            return mem[i][target];
        }

        if (mem[i].count(target))
        {
            return mem[i][target];
        }

        mem[i][target] = dfs(i + 1, nums, target) || dfs(i + 1, nums, target - nums[i]);

        return mem[i][target];
    }
    unordered_map<int, unordered_map<int, bool>> mem;
    bool DP(const vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1));
        for (int i = 0; i < n; ++i)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= target; ++j)
            {
                if (j < nums[i - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int sums = accumulate(nums.begin(), nums.end(), 0);
        int target = sums / 2;
        if (target * 2 != sums)
        {
            return false;
        }

        // return dfs(0, nums, target);
        return DP(nums, target);
    }
};

void test416()
{
    Solution416 solution;
    // [3,3,3,4,5]
    vector<int> nums = {3, 3, 3, 4, 5};
    cout << (solution.canPartition(nums) ? "true" : "false") << endl;
}

#endif // !_LEETCODE_DYNAMIC_KNAPSACK_LEETCODE416_H_