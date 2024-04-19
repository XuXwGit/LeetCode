#ifndef _LEETCODE_41_H_
#define _LEETCODE_41_H_

#include <vector>
#include <algorithm>
using namespace std;

class Solution41 {
 public:
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] <= 0 || nums[i] > nums.size()) {
        nums[i] = nums.size() + 1;
      }
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0 && nums[i] <= nums.size()) {
        nums[nums[i] - 1] = 0;
      }
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        return i + 1;
      }
    }

    return 1;
  }
};


void test41() {
  Solution41 solution;
  vector<int> nums = {3, 4, -1, 1};
  int result = solution.firstMissingPositive(nums);
  printf("result: %d\n", result);
}

#endif  // !_LEETCODE_41_H_