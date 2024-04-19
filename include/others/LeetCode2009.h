#ifndef _LEETCODE_2009_H_
#define _LEETCODE_2009_H_

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution2009 {
public:
    int minOperations(vector<int>& nums) {
        set<int> numset;
        for(int x: nums){
            numset.insert(x);
        }

        vector<int> newnums(numset.begin(), numset.end());

        int count = 0;
        int left = 0;
        int right = 0;
        while(right < newnums.size()){
            while(right < newnums.size() && newnums[right] <= newnums[left] + nums.size() - 1){
                right ++;
                count = max(count, right - left);
            }
            left ++;
            right = left;
        }

        return nums.size() - count;
    }
};

void test2009(){
    Solution2009 solution;

    vector<int> nums = {1,2,3,5,6};
    cout << solution.minOperations(nums) << endl;

    nums = {41,33,29,33,35,26,47,24,18,28};
    cout << solution.minOperations(nums) << endl;

    nums = {1, 1, 1};
    cout << solution.minOperations(nums) << endl;
}

#endif