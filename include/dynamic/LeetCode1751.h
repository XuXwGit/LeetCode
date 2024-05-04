/*
same as LeetCode1235.h
2D version
*/

/*
1751. 最多可以参加的会议数目 II
已解答

给你一个 events 数组，其中 events[i] = [startDayi, endDayi, valuei] ，表示第 i 个会议在 startDayi 天开始，第 endDayi 天结束，如果你参加这个会议，你能得到价值 valuei 。同时给你一个整数 k 表示你能参加的最多会议数目。

你同一时间只能参加一个会议。如果你选择参加某个会议，那么你必须 完整 地参加完这个会议。会议结束日期是包含在会议内的，也就是说你不能同时参加一个开始日期与另一个结束日期相同的两个会议。

请你返回能得到的会议价值 最大和 。
*/

#ifndef _LEETCODE1751_H
#define _LEETCODE1751_H

class Solution1751 {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](auto& le, auto& rh){return le[1] < rh[1];});

        vector<vector<int>> dp(n, vector<int>(k, 0));

        dp[0][0] = events[0][2];
        for(int i = 1; i<n; ++i){
            dp[i][0] = max(dp[i-1][0], events[i][2]);
        }

        for(int i = 1; i<n; ++i){
            for(int j = 1; j<k; ++j){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

                int jj = lower_bound(events.begin(), 
                                    events.begin() + i, 
                                    vector<int>{0, events[i][0], 0},
                                    [&](auto& le, auto& rh){return le[1] < rh[1];})
                        - events.begin();
            
                if(jj && dp[i][j] < dp[jj-1][j-1] + events[i][2]){
                    dp[i][j] = dp[jj-1][j-1] + events[i][2];
                }
            }
        }

        return dp.back().back();
    }
};

void test1751(){
    cout << " ==== test1751 ====" << endl;
    Solution1751 sol;
    vector<vector<int>> events = {{1,2,4},{3,4,3},{2,3,1}};
    int k = 2;
    cout << sol.maxValue(events, k) << endl;
}

#endif // _LEETCODE1751_H