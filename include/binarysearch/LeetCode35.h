/*
35. 搜索插入位置
已解答

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
*/

#ifndef _BINARYSEARCH_LEETCODE35_H_
#define _BINARYSEARCH_LEETCODE35_H_


class Solution35 {
public:
    int searchInsert(vector<int>& nums, int target) {
        // return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(nums.back() < target){
            return nums.size();
        }
        if(nums.front() > target){
            return 0;
        }
        int left = 0; 
        int right = nums.size() - 1;
        int mid = 0;
        while(left < right){
            mid = left + (right - left)/2;
            if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};

void test35(){
    vector<int> nums = {1,3,5,6};
    int target = 5;
    Solution35 solution;
    cout << solution.searchInsert(nums, target) << endl;
    target = 2;
    cout << solution.searchInsert(nums, target) << endl;
}


#endif // !_BINARYSEARCH_LEETCODE35_H_