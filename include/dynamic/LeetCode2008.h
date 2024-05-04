/*
2008. 出租车的最大盈利

你驾驶出租车行驶在一条有 n 个地点的路上。这 n 个地点从近到远编号为 1 到 n ，你想要从 1 开到 n ，通过接乘客订单盈利。你只能沿着编号递增的方向前进，不能改变方向。

乘客信息用一个下标从 0 开始的二维数组 rides 表示，其中 rides[i] = [starti, endi, tipi] 表示第 i 位乘客需要从地点 starti 前往 endi ，愿意支付 tipi 元的小费。

每一位 你选择接单的乘客 i ，你可以 盈利 endi - starti + tipi 元。你同时 最多 只能接一个订单。

给你 n 和 rides ，请你返回在最优接单方案下，你能盈利 最多 多少元。

注意：你可以在一个地点放下一位乘客，并在同一个地点接上另一位乘客。
*/

#ifndef _LEETCODE2008_H
#define _LEETCODE2008_H

class Solution2008 {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), [](auto& le, auto& rh){return le[1] < rh[1];});

        int m = rides.size();
        vector<long long> dp(m, 0);
        dp[0] = (long long)rides[0][2] + rides[0][1] - rides[0][0];

        for(int i = 1; i<m; ++i){
            long long income = (long long)rides[i][2] + rides[i][1] - rides[i][0];
            dp[i] = max(dp[i-1], income);
            int j = upper_bound(rides.begin(), rides.begin()+i, vector<int>{0,rides[i][0],0},
                                [](const auto& le, const auto& rh){return le[1] < rh[1];}) 
                    - rides.begin();
            if(j) dp[i] = max(dp[i], dp[j-1] + income);
        }

        return dp.back();
    }
};

void test2008(){
    cout << " ==== test2008 ====" << endl;
    Solution2008 sol;
    int n = 5;
    vector<vector<int>> rides = {{2,5,4},{1,5,1}};
    cout << sol.maxTaxiEarnings(n, rides) << endl;
}

#endif // _LEETCODE2008_H