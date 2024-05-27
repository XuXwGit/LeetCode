/*
309. 买卖股票的最佳时机含冷冻期
已解答
中等
相关标签
相关企业
给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。



示例 1:

输入: prices = [1,2,3,0,2]
输出: 3
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
示例 2:

输入: prices = [1]
输出: 0


提示：

1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/

#ifndef _LEETCODE_DYNAMIC_PROGRAMMING_STOCK_LEETCODE309_H_
#define _LEETCODE_DYNAMIC_PROGRAMMING_STOCK_LEETCODE309_H_

class Solution309
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
        {
            return 0;
        }

        int n = prices.size();

        vector<int> dp0(n, 0);
        vector<int> dp1(n, 0);

        dp1[0] = -prices[0];
        dp0[1] = max(0, prices[1] - prices[0]);
        dp1[1] = max(dp1[0], -prices[1]);
        for (int i = 2; i < n; ++i)
        {
            dp0[i] = max(dp0[i - 1], dp1[i - 1] + prices[i]);
            dp1[i] = max(dp1[i - 1], dp0[i - 2] - prices[i]);
        }

        return dp0[n - 1];
    }
};

void test309()
{
    vector<int> prices = {1, 2, 3, 0, 2};
    Solution309 solution309;
    assert(solution309.maxProfit(prices) == 3);
}

#endif // !_LEETCODE_DYNAMIC_PROGRAMMING_STOCK_LEETCODE309_H_