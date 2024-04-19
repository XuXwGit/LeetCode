#ifndef _LEETCODE_200_
#define _LEETCODE_200_

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution200 {
public:
    void resetIsland(vector<string>& grid, int row, int col) {
        if (grid[row][col] == '0') {
            return;;
        }

        grid[row][col] = '0';

        if (row > 0) {
            resetIsland(grid, row - 1, col);
        }
        if (row < grid.size() - 1) {
            resetIsland(grid, row + 1, col);
        }
        if (col > 0) {
            resetIsland(grid, row, col - 1);
        }
        if (col < grid[0].size() - 1) {
            resetIsland(grid, row, col + 1);
        }

    }
    int numIslands(vector<string>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    res++;
                    resetIsland(grid, i, j);
                }
            }
        }
        return res;
    }
};


void test200() {
    Solution200 solution;

    vector<string> grid = { "11110", "11010", "11000", "00000" };
    cout << solution.numIslands(grid) << endl;

    grid = { "11000", "11000", "00100", "00011" };
    cout << solution.numIslands(grid) << endl;
}

#endif // !_LEETCODE_200_
