/*
123. 买卖股票的最佳时机 III
已解答
困难
相关标签
相关企业
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。



示例 1:

输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
示例 2：

输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3：

输入：prices = [7,6,4,3,1]
输出：0
解释：在这个情况下, 没有交易完成, 所以最大利润为 0。
示例 4：

输入：prices = [1]
输出：0


提示：

1 <= prices.length <= 105
0 <= prices[i] <= 105
*/

#ifndef _LEETCODE_DYNAMIC_PROGRAMMING_STOCK_LEETCODE123_H_
#define _LEETCODE_DYNAMIC_PROGRAMMING_STOCK_LEETCODE123_H_

class Solution123
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int k = 2;

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
                dp0[i][j] = max(dp0[i - 1][j], dp1[i - 1][j] + prices[i]);
                if (j == 0)
                {
                    dp1[i][j] = max(dp1[i - 1][j], -prices[i]);
                }
                else
                {
                    dp1[i][j] = max(dp1[i - 1][j], dp0[i - 1][j - 1] - prices[i]);
                }
            }
        }

        return dp0[n - 1][k - 1];
    }
};

void test123()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    Solution123 solution123;
    int res = solution123.maxProfit(prices);
    cout << res << endl;
}

#endif // !_LEETCODE_DYNAMIC_PROGRAMMING_STOCK_LEETCODE123_H_