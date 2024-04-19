#ifndef _LEETCODE_46_H_
#define _LEETCODE_46_H_

#include <vector>
#include <iostream>

using namespace std;

class Solution46 {
 private:
  void swap(vector<int>& vec, int i, int j) {
    if (i == j) {
      return;
    }
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
  }
  void backtrack(int level, vector<int>& solution, vector<vector<int>>& res) {
    if (level == solution.size()) {
      res.push_back(solution);
      return;
    } else {
      for (int i = level; i < solution.size(); ++i) {
        swap(solution, level, i);
        backtrack(level + 1, solution, res);
        swap(solution, level, i);
      }
    }
  }

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> sol = nums;
    backtrack(0, sol, res);
    return res;
  }
};


void test46() {
  Solution46 solution46;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> res = solution46.permute(nums);
  for (auto i : res) {
	for (auto j : i) {
	  cout << j << " ";
	}
	cout << endl;
  }
}

#endif  // !_LEETCODE_46_H_
