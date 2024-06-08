/*
279. 完全平方数
已解答
中等
相关标签
相关企业
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。



示例 1：

输入：n = 12
输出：3
解释：12 = 4 + 4 + 4
示例 2：

输入：n = 13
输出：2
解释：13 = 4 + 9

提示：

1 <= n <= 10^4
*/

#ifndef _LEETCODE_DP_KNAPNACK_LEETCODE279_H_
#define _LEETCODE_DP_KNAPNACK_LEETCODE279_H_

class Solution279
{
private:
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(int i, int taregt)
    {
        if (i * i > taregt)
        {
            return INT_MAX / 2;
        }
        else if (i * i == taregt)
        {
            return 1;
        }

        if (memo[i][taregt] != 0)
        {
            return memo[i][taregt];
        }

        memo[i][taregt] = min(dfs(i + 1, taregt), dfs(i, taregt - i * i) + 1);

        return memo[i][taregt];
    }
    int DP(int n)
    {
        vector<int> dp(n + 1, INT_MAX / 2);

        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }

public:
    int numSquares(int n)
    {
        // return dfs(1, n);
        return DP(n);
    }
};

void test279()
{
    Solution279 solution279;
    cout << 12 << ": " << solution279.numSquares(12) << endl;
    cout << 13 << ": " << solution279.numSquares(13) << endl;
    cout << 4703 << ": " << solution279.numSquares(4703) << endl;
}

#endif // !_LEETCODE_DP_KNAPNACK_LEETCODE279_H_
