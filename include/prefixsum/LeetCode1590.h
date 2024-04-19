#ifndef _LEETCODE_1590_H_
#define _LEETCODE_1590_H_

#include <algorithm>
#include <iostream>
using namespace std;

class Solution1590 {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long k = accumulate(nums.begin(), nums.end(), 0ll)%p;
        // 0ll / 0LL means : long long 0
        if(k == 0){
            return 0;
        }

        unordered_map<int, int> maps;
        // set bound
        maps[0] = -1;

        int sum = 0;
        
        int minsub = INT_MAX;
        for(int i = 0; i<nums.size(); ++i){
            sum = (sum + nums[i])%p;
            int target = (sum - k + p)%p;
            if(maps.count(target)){
                minsub = min(minsub, i - maps[target]);
            }
            maps[sum] = i;
        }

        return minsub >= nums.size() ? -1 : minsub;
    }
};

void test1590(){
    Solution1590 solution;

    vector<int> nums = {3,1,4,2};
    int p = 6;
    cout << solution.minSubarray(nums, p) << endl;

    nums = {6,3,5,2};
    p = 9;
    cout << solution.minSubarray(nums, p) << endl;

    // [1000000000,1000000000,1000000000]
    // p = 3
    nums = {1000000000,1000000000,1000000000};
    p = 3;
    cout << solution.minSubarray(nums, p) << endl;

    // [8,32,31,18,34,20,21,13,1,27,23,22,11,15,30,4,2]
    // p = 148
    nums = {8,32,31,18,34,20,21,13,1,27,23,22,11,15,30,4,2};
    p = 148;
    cout << solution.minSubarray(nums, p) << endl;
}


#endif // _LEETCODE_1590_H_