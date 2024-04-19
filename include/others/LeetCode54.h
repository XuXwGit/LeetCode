#ifndef _LEETCODE_54_H_
#define _LEETCODE_54_H_

#include <vector>
#include <iostream>

using namespace std;

class Solution54 {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;

    int len = matrix[0].size();
    int high = matrix.size();
    int level = 0;

    while (res.size() < matrix[0].size() * matrix.size() && len > 0 &&
           high > 0) {
      for (int i = level; i < level + len; ++i) {
        res.push_back(matrix[level][i]);
      }

      for (int j = level + 1; j < level + high; ++j) {
        res.push_back(matrix[j][matrix[0].size() - 1 - level]);
      }

      for (int i = level + len - 2; i >= level && high>1; --i) {
        res.push_back(matrix[matrix.size() - 1 - level][i]);
      }

      for (int j = level + high - 2; j > level; --j) {
        res.push_back(matrix[j][level]);
      }

      level++;
      len = len - 2;
      high = high - 2;
    }

    return res;
  }
};

void test54() {
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  Solution54 solution54;
  vector<int> res = solution54.spiralOrder(matrix);
  for (int i = 0; i < res.size(); ++i) {
	cout << res[i] << " ";
  }
  cout << endl;
}

#endif  // !_LEETCODE_54_H_
