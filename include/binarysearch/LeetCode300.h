#ifndef _LEETCODE300_H_
#define _LEETCODE300_H_

class Solution300 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> d;
        d.push_back(nums[0]);

        for(int i = 1; i<nums.size(); ++i){
            if(nums[i] > d.back()){
                d.push_back(nums[i]);
            }else{
                int left = 0;
                int right = d.size() - 1;
                int mid = 0;
                while(left < right){
                    mid = left + (right - left)/2;
                    if(d[mid] < nums[i]){
                        left = mid + 1;
                    }else{
                        right = mid;
                    }
                }
                d[left] = nums[i];
            }
        }

        return d.size();
    }
};

void test300(){
    Solution300 solution;

    vector<int> nums = {10,9,2,5,3,4};
    cout << (solution.lengthOfLIS(nums) == 3) << endl;
}

#endif