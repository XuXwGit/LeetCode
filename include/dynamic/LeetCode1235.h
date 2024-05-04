/*
same as LeetCode1751.h
*/

/*
1235. 规划兼职工作
困难

你打算利用空闲时间来做兼职工作赚些零花钱。

这里有 n 份兼职工作，每份工作预计从 startTime[i] 开始到 endTime[i] 结束，报酬为 profit[i]。

给你一份兼职工作表，包含开始时间 startTime，结束时间 endTime 和预计报酬 profit 三个数组，请你计算并返回可以获得的最大报酬。

注意，时间上出现重叠的 2 份工作不能同时进行。

如果你选择的工作在时间 X 结束，那么你可以立刻进行在时间 X 开始的下一份工作。
*/

#ifndef _LEETCODE1235_H
#define _LEETCODE1235_H

class Solution1235 {
private:
    struct job{
        int startTime;
        int endTime;
        int profit;

        bool operator<(const job& rh) const{
            return endTime < rh.endTime;
        }
    };
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> combine;
        combine.push_back({0,0,0});
        for(int i = 0; i<n; ++i){
            combine.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(combine.begin(), combine.end(), [](auto& x, auto& y){return x[1] < y[1];});

        vector<int> dp(n+1, 0);
        dp[0] = 0;
        for(int i = 1; i<=n; ++i){
            dp[i] = max(dp[i-1], combine[i][2]);
            // > : upper_bound 返回的是第一个大于目标值的迭代器
            // >= : lower_bound 返回的是第一个大于等于目标值的迭代器
            // < : lower_bound - 1
            // <= : upper_bound - 1
            int j = upper_bound(combine.begin(), combine.begin()+i, vector<int>{0, combine[i][0], 0}, [](auto& x, auto& y){return x[1] < y[1];}) - combine.begin();
            dp[i] = max(dp[i], dp[j-1] + combine[i][2]);
        }

        return dp[n];
    }
};

void test1235(){
    Solution1235 solution;
    vector<int> startTime = {1,2,3,3};
    vector<int> endTime = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    cout << solution.jobScheduling(startTime, endTime, profit) << endl;
}

#endif // `_LEETCODE1235_H`