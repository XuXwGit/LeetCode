/*
same as LeetCode1235.h

*/
/*
2830. 销售利润最大化
给你一个整数 n 表示数轴上的房屋数量，编号从 0 到 n - 1 。

另给你一个二维整数数组 offers ，其中 offers[i] = [starti, endi, goldi] 表示第 i 个买家想要以 goldi 枚金币的价格购买从 starti 到 endi 的所有房屋。

作为一名销售，你需要有策略地选择并销售房屋使自己的收入最大化。

返回你可以赚取的金币的最大数目。

注意 同一所房屋不能卖给不同的买家，并且允许保留一些房屋不进行出售。
*/

#ifndef _LEETCODE2830_H
#define _LEETCODE2830_H

class Solution2830 {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size();
        sort(offers.begin(), offers.end(), [](auto& le, auto& rh){return le[1] < rh[1];});
        vector<int> dp(m, 0);
        dp[0] = offers[0][2];
        for(int i = 1; i<m; ++i){
            dp[i] = max(dp[i-1], offers[i][2]);
            int j = lower_bound(offers.begin(), offers.begin() + i, vector<int>{0, offers[i][0], 0}, [](auto& le, auto& rh){return le[1] < rh[1];}) - offers.begin();
            if(j) dp[i] = max(dp[i], dp[j-1] + offers[i][2]);
        }

        return dp.back();
    }
};

void test2830(){
    Solution2830 sol;
    int n = 5;
    vector<vector<int>> offers = {{2,5,4},{1,5,1}};
    cout << sol.maximizeTheProfit(n, offers) << endl;
}

#endif // _LEETCODE2830_H