/*

*/


#ifndef _BACKTRACK_LEETCODE36_H_
#define _BACKTRACK_LEETCODE36_H_


class Solution36 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9);
        vector<set<int>> cols(9);
        vector<set<int>> blocks(9);
        for(int i = 0; i<9; ++i){
            for(int j = 0; j<9; ++j){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    if(rows[i].count(board[i][j] - '1') 
                    || cols[j].count(board[i][j] - '1') 
                    || blocks[(i/3)*3+j/3].count(board[i][j]-'1')){
                        return false;
                    }else{
                        rows[i].insert(board[i][j] - '1');
                        cols[j].insert(board[i][j] - '1');
                        blocks[(i/3)*3+j/3].insert(board[i][j]-'1');
                    }
                }
            }
        }

        return true;
    }
};



void test36(){
    //[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
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
    Solution36 s;
    cout << s.isValidSudoku(board) << endl;
}

#endif // !_BACKTRACK_LEETCODE36_H_