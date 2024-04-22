/*
16. 最接近的三数之和

给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。
*/

#ifndef _DOUBLE_POINTER_LEETCODE16_H_
#define _DOUBLE_POINTER_LEETCODE16_H_


class Solution16 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        int gap = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-2; ++i){
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(target - sum) < gap){
                    res = sum;
                    gap = abs(target - sum);
                }
                if(sum == target){
                    return sum;
                }
                else if(sum > target){
                    right --;
                }else{
                    left ++;
                }
            }
        }

        return res;
    }
};


void test16(){
    Solution16 s;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << s.threeSumClosest(nums, target) << endl;

    nums = {1, 1, 1, 0};
    target = -100;
    cout << s.threeSumClosest(nums, target) << endl;

    // [0,1,2]
    // 3
    nums = {0, 1, 2};
    target = 3;
    cout << s.threeSumClosest(nums, target) << endl;

}

#endif // !_DOUBLE_POINTER_LEETCODE16_H_