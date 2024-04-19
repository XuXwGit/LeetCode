#ifndef _LEETCODE_322_H_
#define _LEETCODE_322_H_

#include <vector>
#include <iostream>
#include <limits.h>
  
using namespace std;

class Solution322 {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> f = vector<int>(amount + 1, -1);
    f[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      int min_f = INT_MAX;
      for (int j = 0; j < coins.size(); ++j) {
        if (i - coins[j] >= 0 && f[i - coins[j]] != -1)
          min_f = min(min_f, f[i - coins[j]] + 1);
      }
      if (min_f < INT_MAX)
          f[i] = min_f;
    }

    return f.back();
  }
};

void test322() {
  Solution322 solution;
  vector<int> coins = {1, 2, 5};
  cout << solution.coinChange(coins, 11) << endl;
}

#endif  // !_LEETCODE_322_H_
