/*
198. 打家劫舍
// Easy
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
*/

#ifndef _DYNAMIC_LEETCODE198_H_
#define _DYNAMIC_LEETCODE198_H_


class Solution198 {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums[0];
        }

        int f_n_2 = 0;
        int f_n_1 = nums[0];
        int f_n = max(f_n_2 + nums[1], f_n_1);

        for(int i = 2; i<nums.size(); ++i){
            f_n_2 = f_n_1;
            f_n_1 = f_n;
            f_n = max(f_n_2 + nums[i], f_n_1);
        }

        return f_n;
    }
};


void test198(){
    Solution198 s;
    vector<int> nums = {2,7,9,3,1};
    cout << s.rob(nums) << endl;
}

#endif // !_DYNAMIC_LEETCODE198_H_