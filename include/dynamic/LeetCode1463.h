/*1463. 摘樱桃 II
困难

给你一个 rows x cols 的矩阵 grid 来表示一块樱桃地。 grid 中每个格子的数字表示你能获得的樱桃数目。

你有两个机器人帮你收集樱桃，机器人 1 从左上角格子 (0,0) 出发，机器人 2 从右上角格子 (0, cols-1) 出发。

请你按照如下规则，返回两个机器人能收集的最多樱桃数目：

从格子 (i,j) 出发，机器人可以移动到格子 (i+1, j-1)，(i+1, j) 或者 (i+1, j+1) 。
当一个机器人经过某个格子时，它会把该格子内所有的樱桃都摘走，然后这个位置会变成空格子，即没有樱桃的格子。
当两个机器人同时到达同一个格子时，它们中只有一个可以摘到樱桃。
两个机器人在任意时刻都不能移动到 grid 外面。
两个机器人最后都要到达 grid 最底下一行。
*/

/*
输入：grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
输出：24
解释：机器人 1 和机器人 2 的路径在上图中分别用绿色和蓝色表示。
机器人 1 摘的樱桃数目为 (3 + 2 + 5 + 2) = 12 。
机器人 2 摘的樱桃数目为 (1 + 5 + 5 + 1) = 12 。
樱桃总数为： 12 + 12 = 24 。
*/

#ifndef _LEETCODE1463_H_
#define _LEETCODE1463_H_

class Solution1463 {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(
            rows, vector<vector<int>>(cols, vector<int>(cols, -1)));

        dp[0][0][cols - 1] = grid[0][0] + grid[0][cols-1];
        for (int i = 1; i < rows; ++i) {
            for (int j1 = 0; j1 < cols; ++j1) {
                for (int j2 = 0; j2 < cols; ++j2) {
                    int best = -1;
                    for (int jj1 = j1 - 1; jj1 <= j1 + 1; ++jj1) {
                        for (int jj2 = j2 - 1; jj2 <= j2 + 1; ++jj2) {
                            if(jj1 >= 0 && jj1 < cols
                            && jj2 >= 0 && jj2 < cols 
                            && dp[i - 1][jj1][jj2] != -1){
                                if(jj1 != jj2){
                                    best =
                                        max(best, dp[i - 1][jj1][jj2] +
                                                            grid[i][j1] +
                                                            grid[i][j2]);                                    
                                }else{
                                    best =
                                        max(best,
                                            dp[i - 1][jj1][jj2] + grid[i][j1]);
                                }
                            }
                        }
                    }
                    dp[i][j1][j2] = best;
                }
            }
        }

        int res = 0;
        for (int j1 = 0; j1 < cols; ++j1) {
            for (int j2 = 0; j2 < cols; ++j2) {
                res = max(res, dp[rows - 1][j1][j2]);
            }
        }

        return res;
    }
};


void test1463(){
    cout << "Leetcode 1463: " << endl;
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    Solution1463 s;
    cout << s.cherryPickup(grid) << endl;

    vector<vector<int>> grid2 = {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
    cout << s.cherryPickup(grid2) << endl;
}


#endif // !_LEETCODE1463_H_