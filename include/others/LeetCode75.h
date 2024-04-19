#ifndef LEETCODE75_H
#define LEETCODE75_H

#include <vector>
#include <iostream>

using namespace std;

class Solution75 {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> left_mins = vector<int>(nums.size(), nums.front());
        vector<int> right_maxs = vector<int>(nums.size(), nums.back());

        for(int i = 1; i<nums.size(); ++i){
            left_mins[i] = min(left_mins[i-1], nums[i-1]);
        }
        for(int i = nums.size() -  2; i >= 0; --i){
            right_maxs[i] = max(right_maxs[i+1], nums[i+1]);
        }

        for(int i = 1; i<nums.size()-1; ++i){
            if(nums[i] < right_maxs[i] && nums[i] > left_mins[i])
                return true;  
        } 

        return false;
    }
};

void test75(){
    Solution75 solution;
    vector<int> nums = {5,4,3,2,1};
    cout << solution.increasingTriplet(nums) << endl;
}

#endif