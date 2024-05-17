#ifndef _LEETCODE_994_
#define _LEETCODE_994_
#include <vector>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution994 {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> rotting_q;
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                if(grid[i][j] == 2){
                    rotting_q.emplace(i, j);
                }
            }
        }

        int res = 0;
        vector<vector<int>> direction = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        while(!rotting_q.empty()){
            int num_rot = rotting_q.size();
            for(int i = 0; i<num_rot; ++i){
                for(int j = 0; j<4; ++j){
                    int x = rotting_q.front().first  + direction[j][0];
                    int y = rotting_q.front().second + direction[j][1];
                    if(x >= 0 && x < m
                        && y >= 0 && y < n
                        && grid[x][y] == 1){
                        rotting_q.emplace(x, y);
                        grid[x][y] = 2;
                    }
                }
                rotting_q.pop();
            }
            if(!rotting_q.empty()){
                res ++;
            }
        }

        int count = 0;
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return res;
    }
};

void test994() {
  // [[2,1,1],[1,1,0],[0,1,1]]
  vector<vector<int>> grid = {
    {2, 1, 1},
    {1, 1, 0},
    {0, 1, 1}};
  Solution994 solution;
  solution.orangesRotting(grid);
}

#endif  // !_LEETCODE_994_
