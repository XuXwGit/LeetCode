#ifndef _LEETCODE_84_H_
#define _LEETCODE_84_H_

#include <vector>
#include <stack>
#include <iostream>

using namespace std;


class Solution84 {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int minS = 0;

    heights.push_back(0);

    stack<int> sta;
    sta.push(-1);
    sta.push(0);

    for (int i = 1; i < heights.size(); ++i) {
      while (sta.size()>1 && heights[sta.top()] > heights[i]) {
        int heigh = heights[sta.top()];

        sta.pop();

        minS = max(minS, heigh * (i - sta.top() - 1));
      }
      sta.push(i);
    }

    return minS;
  }
};

void test84() {
  Solution84 solution;
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  cout << solution.largestRectangleArea(heights) << endl;
}

#endif  // !_LEETCODE_84_H_
