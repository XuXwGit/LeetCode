#ifndef _LEETCODE_189_
#define _LEETCODE_189_

#include <vector>

using namespace std;

class Solution189 {
 public:
  void rotate(vector<int>& nums, int k) {
    if (k == 0 || nums.size() - k < 0) {
      return;
    }
    vector<int> tempvec(nums.end() - k, nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      int temp = nums[i];
      nums[i] = tempvec[i % k];
      tempvec[i % k] = temp;
    }
  }
};

void test189() {
  vector<int> nums = {1};
  int k = 2;
  Solution189 solution;
  solution.rotate(nums, k);
}

#endif  // !_LEETCODE_189_
