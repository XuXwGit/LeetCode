/*
120. 三角形最小路径和
已解答
中等
相关标签
相关企业
给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

示例 1：

输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
*/


#ifndef _DP_LEETCODE120_H
#define _DP_LEETCODE120_H

class Solution120 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;

        for(int i = 1; i<triangle.size(); ++i){
            for(int j = 0; j<= i; ++j){
                if(j > 0 && j < i){
                    dp[i][j] += min(dp[i-1][j-1], dp[i-1][j]);
                }else if(j == 0){
                    dp[i][j] += dp[i-1][j];
                }else{
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }

        return *(min_element(dp.back().begin(), dp.back().end()));
    }
};


void test120(){
    Solution120 sol;
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << sol.minimumTotal(triangle) << endl;
}

#endif // !_DP_LEETCODE120_H