/*
377. 组合总和 Ⅳ

给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。

题目数据保证答案符合 32 位整数范围。

请注意，顺序不同的序列被视作不同的组合。
*/

#ifndef _DYNAMIC_PROGRAMMING_LEETCODE377_H_
#define _DYNAMIC_PROGRAMMING_LEETCODE377_H_


class Solution377 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 0; i<=target; ++i){
            for(auto x: nums){
                if(x<=i){
                    dp[i] += dp[i-x];
                }
            }
        }

        return dp[target];
    }
};


void test377(){
    Solution377 s;
    vector<int> nums = {1,2,3};
    int target = 4;
    cout << s.combinationSum4(nums, target) << endl;
}


#endif // !_DYNAMIC_PROGRAMMING_LEETCODE377_H_