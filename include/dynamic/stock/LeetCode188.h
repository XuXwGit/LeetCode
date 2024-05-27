/*
188. 买卖股票的最佳时机 IV
困难
相关标签
相关企业
给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。



示例 1：

输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2：

输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。


提示：

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/

#ifndef _LEETCODE_DYNAMIC_PROGRAMMING_STOCK_LEETCODE188_H_
#define _LEETCODE_DYNAMIC_PROGRAMMING_STOCK_LEETCODE188_H_

class Solution188
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<int>> dp0(n, vector<int>(k, 0));
        vector<vector<int>> dp1(n, vector<int>(k, 0));
        for (int j = 0; j < k; ++j)
        {
            dp1[0][j] = -prices[0];
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                if (j == 0)
                {
                    dp1[i][j] = max(dp1[i - 1][j], -prices[i]);
                }
                else
                {
                    dp1[i][j] = max(dp1[i - 1][j], dp0[i - 1][j - 1] - prices[i]);
                }
                dp0[i][j] = max(dp0[i - 1][j], dp1[i - 1][j] + prices[i]);
            }
        }

        return dp0[n - 1][k - 1];
    }
};
void test188()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int k = 2;
    Solution188 solution188;
    cout << solution188.maxProfit(k, prices) << endl;
}

#endif // !_LEETCODE_DYNAMIC_PROGRAMMING_STOCK_LEETCODE188_H_