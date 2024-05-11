/*
805. 数组的均值分割
困难
相关标签
相关企业
给定你一个整数数组 nums

我们要将 nums 数组中的每个元素移动到 A 数组 或者 B 数组中，使得 A 数组和 B 数组不为空，并且 average(A) == average(B) 。

如果可以完成则返回true ， 否则返回 false  。

注意：对于数组 arr ,  average(arr) 是 arr 的所有元素的和除以 arr 长度。

*/


/*
示例 1:

输入: nums = [1,2,3,4,5,6,7,8]
输出: true
解释: 我们可以将数组分割为 [1,4,5,8] 和 [2,3,6,7], 他们的平均值都是4.5。
示例 2:

输入: nums = [3,1]
输出: false
*/


#ifndef _BACKTRACK_LEETCODE805_H_
#define _BACKTRACK_LEETCODE805_H_


class Solution805 {
private:
    unordered_map<int, vector<int>> lefts;

    void backtrack(int l, int r, int sum, vector<int>& nums, int count){
        if(l == r){
            lefts[sum].push_back(count);
            return;
        }else{
            backtrack(l+1, r, sum, nums, count);
            backtrack(l+1, r, sum + nums[l], nums, count + 1);            
        }
    }

    bool dfs(int l, int r, int sum, vector<int>& nums, int count){
        if(l == r){
            if(lefts.count(-sum))
            {
                for(auto x: lefts[-sum]){
                    if(x + count > 0 && x + count < nums.size()){
                        return true;
                    }
                }
            }
            return false;
        }else{
            return dfs(l+1, r, sum, nums, count) || 
                   dfs(l+1, r, sum + nums[l], nums, count+1);            
        }
    }
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int m = n/2;

        int sums = accumulate(nums.begin(), nums.end(), 0);
        for(auto& x: nums){
            x = x*n - sums;
        }

        backtrack(0, m, 0, nums, 0);

        return dfs(m, n, 0, nums, 0);
    }
};

void test805(){
    vector<int> nums = {3, 1};
    Solution805 solution;
    cout << solution.splitArraySameAverage(nums) << endl;
}


#endif // !_BACKTRACK_LEETCODE805_H_