/*
322. 零钱兑换
已解答
中等
相关标签
相关企业
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。



示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3
解释：11 = 5 + 5 + 1
示例 2：

输入：coins = [2], amount = 3
输出：-1
示例 3：

输入：coins = [1], amount = 0
输出：0


提示：

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4
*/

#ifndef _LEETCODE_DP_KNAPNACK_LEETCODE322_H_
#define _LEETCODE_DP_KNAPNACK_LEETCODE322_H_

class Solution322
{
private:
    int dfs(int i, vector<int> &nums, int target, vector<vector<int>> &memo)
    {
        if (i >= nums.size())
        {
            return target == 0 ? 0 : INT_MAX / 2;
        }

        if (memo[i][target] != -1)
        {
            return memo[i][target];
        }

        if (target < nums[i])
        {
            memo[i][target] = dfs(i + 1, nums, target, memo);
        }
        else
        {
            // dp[i][c] = min(dp[i+1][c], dp[i][c-nums[i]] + v[i]);
            memo[i][target] = min(dfs(i + 1, nums, target, memo), dfs(i, nums, target - nums[i], memo) + 1);
        }

        return memo[i][target];
    }

    int DP(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, INT_MAX / 2));

        dp[0][0] = 0;
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
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - nums[i - 1]] + 1);
                }
            }
        }

        return dp[n][target];
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<vector<int>> memo = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
        int res = dfs(0, coins, amount, memo);
        // int res = DP(coins, amount);

        res = res < INT_MAX / 2 ? res : -1;

        return res;
    }
};

void test322()
{
    Solution322 solution;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << solution.coinChange(coins, amount) << endl;
}

#endif // !_LEETCODE_DP_KNAPNACK_LEETCODE322_H_