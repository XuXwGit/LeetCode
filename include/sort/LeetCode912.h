#ifndef _LEETCODE_912_H_
#define _LEETCODE_912_H_

#include <vector>
#include <iostream>

using namespace std;

class Solution912 {
 public:
  vector<int> sortArray(vector<int>& nums) {
    vector<int> res(nums.size());
    vector<int> pri = nums;
    for (int seg = 1; seg < pri.size(); seg += seg) {
      for (int left = 0; left < pri.size(); left += seg * 2) {
        int mid = left + seg < pri.size() ? left + seg : pri.size();
        int right = left + seg * 2 < pri.size() ? left + seg * 2 : pri.size();
        int i = left, j = mid, k = left;
        while (i < mid && j < right) {
          res[k++] = pri[i] < pri[j] ? pri[i++] : pri[j++];
        }
        while (i < mid) {
          res[k++] = pri[i++];
        }
        while (j < right) {
          res[k++] = pri[j++];
        }
      }
      if (seg * 2 < nums.size()) {
        swap(res, pri);
      }
    }
    return res;
  }
};


void test912() {
  vector<int> nums = {5, 2, 3, 1};  
  Solution912 solution912;
  vector<int> res = solution912.sortArray(nums);
  for (size_t i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}

#endif  // !_LEETCODE_912_H_
