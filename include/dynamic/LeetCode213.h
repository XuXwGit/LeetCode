/*
213. 打家劫舍 II
// Easy

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
*/

#ifndef _DYNAMIC_LEETCODE213_H_
#define _DYNAMIC_LEETCODE213_H_


class Solution213 {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums[0];
        }

        int f_n_2_0 = 0;
        int f_n_1_0 = f_n_2_0;
        int f_n_0 = f_n_1_0 + nums[1];
        for(int i = 2; i<nums.size(); ++i){
            f_n_2_0 = f_n_1_0;
            f_n_1_0 = f_n_0;
            f_n_0 = max(f_n_2_0+nums[i], f_n_1_0);
        }

        int f_n_2_1 = 0;
        int f_n_1_1 = nums[0];
        int f_n_1 = max(f_n_2_1 + nums[1], f_n_1_1);
        for(int i = 2; i<nums.size()-1; ++i){
            f_n_2_1 = f_n_1_1;
            f_n_1_1 = f_n_1;
            f_n_1 = max(f_n_2_1+nums[i], f_n_1_1);
        }

        return max(f_n_0, f_n_1);
    }
};

void test213(){
    Solution213 s;
    vector<int> nums = {2,3,2};
    cout << s.rob(nums) << endl;
    nums = {1,2,3,1};
    cout << s.rob(nums) << endl;
}

#endif // !_DYNAMIC_LEETCODE213_H_