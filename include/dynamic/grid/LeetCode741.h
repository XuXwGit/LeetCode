/*
741. 摘樱桃
已解答
困难
相关标签
相关企业
给你一个 n x n 的网格 grid ，代表一块樱桃地，每个格子由以下三种数字的一种来表示：

0 表示这个格子是空的，所以你可以穿过它。
1 表示这个格子里装着一个樱桃，你可以摘到樱桃然后穿过它。
-1 表示这个格子里有荆棘，挡着你的路。
请你统计并返回：在遵守下列规则的情况下，能摘到的最多樱桃数：

从位置 (0, 0) 出发，最后到达 (n - 1, n - 1) ，只能向下或向右走，并且只能穿越有效的格子（即只可以穿过值为 0 或者 1 的格子）；
当到达 (n - 1, n - 1) 后，你要继续走，直到返回到 (0, 0) ，只能向上或向左走，并且只能穿越有效的格子；
当你经过一个格子且这个格子包含一个樱桃时，你将摘到樱桃并且这个格子会变成空的（值变为 0 ）；
如果在 (0, 0) 和 (n - 1, n - 1) 之间不存在一条可经过的路径，则无法摘到任何一个樱桃。
*/

#ifndef _LEETCODE741_H_
#define _LEETCODE741_H_

class Solution741 {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(2*n-1, vector<vector<int>>(n, vector<int>(n, 0)));

        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                if(i == 0 && j == 0)    continue;
                bool flag1 = i>0? grid[i-1][j] == -1: true;
                bool flag2 = j>0? grid[i][j-1] == -1: true;
                if(flag1 && flag2){
                    grid[i][j] = -1;
                }
            }
        }

        dp[0][0][0] = grid[0][0];
        for(int k = 1; k<2*n-1; ++k){
            for(int x1 = 0; x1<n; ++x1){
                for(int x2 = 0; x2<n; ++x2){
                    int y1 = k - x1;
                    int y2 = k - x2;
                    if(y1 < 0 || y1 >= n || y2 < 0 || y2 >= n){
                        continue;
                    }
                    if(grid[x1][y1] == -1 || grid[x2][y2] == -1){
                        continue;
                    }
                    bool flag11 = x1>0 && grid[x1-1][y1] != -1;
                    bool flag12 = y1>0 && grid[x1][y1-1] != -1;
                    bool flag21 = x2>0 && grid[x2-1][y2] != -1;
                    bool flag22 = y2>0 && grid[x2][y2-1] != -1;
                    int curr = x1 == x2? grid[x1][y1]: grid[x1][y1] + grid[x2][y2];
                    if(flag11 && flag21){
                        dp[k][x1][x2] = max(dp[k][x1][x2], curr + dp[k-1][x1-1][x2-1]);
                    }
                    if(flag11 && flag22){
                        dp[k][x1][x2] = max(dp[k][x1][x2], curr + dp[k-1][x1-1][x2]);
                    }
                    if(flag12 && flag21){
                        dp[k][x1][x2] = max(dp[k][x1][x2], curr + dp[k-1][x1][x2-1]);
                    }
                    if(flag12 && flag22){
                        dp[k][x1][x2] = max(dp[k][x1][x2], curr + dp[k-1][x1][x2]);
                    }
                }
            }
        }
        
        return dp[2*n-2][n-1][n-1];
    }
};

void test741(){
    cout << "LeetCode 741: " << endl;
    vector<vector<int>> grid = {{0,1,-1},{1,0,-1},{1,1,1}};
    Solution741 sl;
    cout << sl.cherryPickup(grid);
}

#endif // !_LEETCODE741_H_