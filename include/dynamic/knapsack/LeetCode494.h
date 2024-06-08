/*
494. 目标和
已解答
中等
相关标签
相关企业
给你一个非负整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。



示例 1：

输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
示例 2：

输入：nums = [1], target = 1
输出：1
*/

#ifndef _LEETCODE_DP_KNAPNACK_LEETCODE494_H_
#define _LEETCODE_DP_KNAPNACK_LEETCODE494_H_

class Solution494
{
private:
    int dfs(int i, vector<int> &nums, int target)
    {
        if (i == nums.size())
        {
            if (target == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (nums[i] > target)
        {
            return dfs(i + 1, nums, target);
        }

        return dfs(i + 1, nums, target) + dfs(i + 1, nums, target - nums[i]);
    }

    int knapnack(vector<int> &nums, int capacity)
    {
        if (capacity < 0)
        {
            return 0;
        }

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= capacity; ++j)
            {
                if (j < nums[i - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][capacity];
    }

    int knapnackII(vector<int> &nums, int capacity)
    {
        if (capacity < 0)
        {
            return 0;
        }

        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(capacity + 1, 0));

        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= capacity; ++j)
            {
                if (j < nums[i - 1])
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][j];
                }
                else
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][j] + dp[(i - 1) % 2][j - nums[i - 1]];
                }
            }
        }

        return dp[n % 2][capacity];
    }

    int knapnackIII(vector<int> &nums, int capacity)
    {
        if (capacity < 0)
        {
            return 0;
        }

        int n = nums.size();
        vector<int> dp(capacity + 1, 0);

        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = capacity; j >= nums[i - 1]; --j)
            {
                dp[j] = dp[j] + dp[j - nums[i - 1]];
            }
        }

        return dp[capacity];
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ps = (sum + target) / 2;

        if (2 * ps - sum != target)
        {
            return 0;
        }

        // return dfs(0, nums, ps);
        // return knapnack(nums, ps);
        // return knapnackII(nums, ps);
        return knapnackIII(nums, ps);
    }
};

void test494()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    Solution494 solution494;
    cout << solution494.findTargetSumWays(nums, target) << endl;
}

#endif // !_LEETCODE_DP_KNAPNACK_LEETCODE494_H_