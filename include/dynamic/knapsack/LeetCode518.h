/*
518. 零钱兑换 II
已解答
中等
相关标签
相关企业
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

假设每一种面额的硬币有无限个。

题目数据保证结果符合 32 位带符号整数。



示例 1：

输入：amount = 5, coins = [1, 2, 5]
输出：4
解释：有四种方式可以凑成总金额：
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
示例 2：

输入：amount = 3, coins = [2]
输出：0
解释：只用面额 2 的硬币不能凑成总金额 3 。
示例 3：

输入：amount = 10, coins = [10]
输出：1


提示：

1 <= coins.length <= 300
1 <= coins[i] <= 5000
coins 中的所有值 互不相同
0 <= amount <= 5000
*/

#ifndef _LEETCODE_DP_KNAPNACK_LEETCODE518_H_
#define _LEETCODE_DP_KNAPNACK_LEETCODE518_H_

class Solution518
{
private:
    int dfs(int i, const vector<int> &nums, int target, vector<vector<int>> &memo)
    {
        if (i >= nums.size())
        {
            return target == 0 ? 1 : 0;
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
            memo[i][target] = dfs(i + 1, nums, target, memo) + dfs(i, nums, target - nums[i], memo);
        }

        return memo[i][target];
    }
    int DP(const vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
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
                    dp[i][j] = dp[i - 1][j] + dp[i][j - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }

public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        // vector<vector<int>> memo(n, vector<int>(amount+1, -1));
        // int res = dfs(0, coins, amount, memo);

        int res = DP(coins, amount);

        return res;
    }
};

void test518()
{
    Solution518 solution518;
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << solution518.change(amount, coins) << endl;
}

#endif // !_LEETCODE_DP_KNAPNACK_LEETCODE518_H_