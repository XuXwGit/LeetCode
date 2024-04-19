#ifndef _LEETCODE_78_H_
#define _LEETCODE_78_H_

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution78 {
 private:
  void backtrack(vector<int>& nums, vector<int>& subset, int level,
                 vector<vector<int>>& res) {
    // return condition
    if (level == nums.size()) {
      res.push_back(subset);
      return;
    }
    // don't put in nums[i]
    backtrack(nums, subset, level + 1, res);

    // put in nums[i]
    subset.push_back(nums[level]);
    backtrack(nums, subset, level + 1, res);
    subset.pop_back();
  }

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> sol;
    backtrack(nums, sol, 0, res);

    return res;
  }
};

void test78() {
  Solution78 solution;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> res = solution.subsets(nums);
  for (auto i : res) {
	for (auto j : i) {
	  cout << j << " ";
	}
	cout << endl;
  }
}

#endif  // !_LEETCODE_78_H_
