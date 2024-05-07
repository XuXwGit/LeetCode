/*
714. 买卖股票的最佳时机含手续费
已解答
中等
相关标签
相关企业
提示
给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
*/

#ifndef _DP_LEETCODE714_H
#define _DP_LEETCODE714_H

class Solution714 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i<n; ++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }

        return dp.back()[0];
    }
};


void test714(){
    Solution714 sol;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << sol.maxProfit(prices, fee) << endl;
}

#endif // !_DP_LEETCODE714_H