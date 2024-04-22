/*
37. 解数独

编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。
*/


#ifndef _LEETCODE_BACKTRACK_LEETCODE37_H_
#define _LEETCODE_BACKTRACK_LEETCODE37_H_

#include "include_std_c++.h"

class Solution37 {
private:
    bool rows[9][9];
    bool cols[9][9];
    bool blocks[3][3][9];
    bool dfs(vector<vector<char>>& board, int x, int y){
        if(y == 9){
            x++;
            y=0;
        }
        if(x == 9){
            return true;
        }
        if(board[x][y] != '.'){
            return dfs(board, x, y+1);
        }

        for(int i = 0; i<9; ++i){
            if(!rows[x][i] && !cols[y][i] && !blocks[x/3][y/3][i]){
                board[x][y] = '1'+i;
                rows[x][i] = true;
                cols[y][i] = true;
                blocks[x/3][y/3][i] = true;
                if(dfs(board, x, y+1)){
                    return true;
                }
                board[x][y] = '.';
                rows[x][i] = false;
                cols[y][i] = false;
                blocks[x/3][y/3][i] = false;
            }
        }

        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(rows, false, sizeof rows);
        memset(cols, false, sizeof cols);
        memset(blocks, false, sizeof blocks);

        for(int i = 0; i<9; ++i){
            for(int j = 0; j<9; ++j){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    rows[i][num] = true;
                    cols[j][num] = true;
                    blocks[i/3][j/3][num] = true;
                }
            }
        }

        dfs(board, 0, 0);
    }
};

void test37(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution37 s;
    s.solveSudoku(board);
    for(auto x: board){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }
}

#endif // !_LEETCODE_BACKTRACK_LEETCODE37_H_