/*
53. 最大子数组和
已解答
中等

给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组
是数组中的一个连续部分。
*/

#ifndef _DYNAMIC_LEETCODE53_H_
#define _DYNAMIC_LEETCODE53_H_


class Solution53 {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp = nums[0];

        int res = dp;
        for(int i = 1; i<n; ++i){
            dp = max(dp + nums[i], nums[i]);
            res = max(res, dp);
        }

        return res;
    }
};


void test53(){
    Solution53 solution53;

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << solution53.maxSubArray(nums) << endl;

    nums = {1};
    cout << solution53.maxSubArray(nums) << endl;

    nums = {5,4,-1,7,8};
    cout << solution53.maxSubArray(nums) << endl;
}

#endif // !_DYNAMIC_LEETCODE53_H_