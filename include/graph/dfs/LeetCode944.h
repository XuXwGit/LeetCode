#include <vector>
#ifndef _LEETCODE_944_
#define _LEETCODE_944_
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution944 {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> que;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 2) {
          que.push(pair<int, int>(i, j));
        }
      }
    }

    int time = 0;
    int level_size = 0;
    while (!que.empty()) {
      level_size = que.size();
      for (int i = 0; i < level_size; ++i) {
        int row = que.front().first;
        int col = que.front().second;
        if (row > 0 && grid[row - 1][col] == 1) {
          grid[row - 1][col] = 2;
          que.push(pair<int, int>(row - 1, col));
        }
        if (col > 0 && grid[row][col - 1] == 1) {
          grid[row][col - 1] = 2;
          que.push(pair<int, int>(row, col - 1));
        }
        if (row < grid.size() - 1 && grid[row + 1][col] == 1) {
          grid[row + 1][col] = 2;
          que.push(pair<int, int>(row + 1, col));
        }
        if (col < grid[0].size() - 1 && grid[row][col + 1] == 1) {
          grid[row][col + 1] = 2;
          que.push(pair<int, int>(row, col + 1));
        }
        que.pop();
      }
      if (!que.empty()) {
        time++;
      }
    }

    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          count++;
        }
      }
    }
    if (count > 0) {
      return -1;
    }

    return time;
  }
};

void test944() {
  vector<vector<int>> grid = {{2, 2}, {1, 1}, {0, 0}, {2, 0}};
  Solution944 solution;
  solution.orangesRotting(grid);
}

#endif  // !_LEETCODE_944_
