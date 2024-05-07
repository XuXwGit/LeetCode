/*
2054. 两个最好的不重叠活动

给你一个下标从 0 开始的二维整数数组 events ，其中 events[i] = [startTimei, endTimei, valuei] 。第 i 个活动开始于 startTimei ，结束于 endTimei ，如果你参加这个活动，那么你可以得到价值 valuei 。你 最多 可以参加 两个时间不重叠 活动，使得它们的价值之和 最大 。

请你返回价值之和的 最大值 。

注意，活动的开始时间和结束时间是 包括 在活动时间内的，也就是说，你不能参加两个活动且它们之一的开始时间等于另一个活动的结束时间。更具体的，如果你参加一个活动，且结束时间为 t ，那么下一个活动必须在 t + 1 或之后的时间开始。
*/

#ifndef _LEETCODE2054_H
#define _LEETCODE2054_H


class Solution2054 {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto& le, auto& rh){return le[1] < rh[1];});
        vector<vector<int>> dp(events.size(), vector<int>(2, 0));
        for(int j = 0; j<2; ++j){
            dp[0][j] = events[0][2];
        }
        for(int i = 1; i<events.size(); ++i){
            dp[i][0] = max(dp[i-1][0], events[i][2]);
        }
        for(int i = 1; i<events.size(); ++i){
            for(int j = 1; j<2; ++j){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                int k = lower_bound(events.begin(), 
                                    events.begin() + i, 
                                    vector<int>{0, events[i][0], 0}, 
                                    [](auto& le, auto& rh){return le[1] < rh[1];})
                                    - events.begin();
                if(k)   dp[i][j] = max(dp[i][j], dp[k-1][j-1] + events[i][2]);
            }
        }

        return dp.back().back();
    }
};


void test2054(){
    Solution2054 sol;
    vector<vector<int>> events = {{1,2,4},{3,4,3},{2,3,1}};
    cout << sol.maxTwoEvents(events) << endl;
}


#endif // _LEETCODE2054_H