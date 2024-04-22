/*
130. 被围绕的区域

给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
*/

#ifndef _GRAPH_DFS_LEETCODE130_H_
#define _GRAPH_DFS_LEETCODE130_H_

#ifdef _USE_DFS_130_

class Solution130 {
private:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(board[i][j] != 'O'){
            return;
        }
        if(board[i][j] == 'O'){
            board[i][j] = 'Y';
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        for(int k = 0; k<4; ++k){
            int x = i + dx[k];
            int y = j + dy[k];
            if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size()){
                dfs(board, x, y);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i<board.size(); ++i){
            dfs(board, i, 0);
            dfs(board, i, board[0].size()-1);
        }

        for(int j = 1; j<board[0].size()-1; ++j){
            dfs(board, 0, j);
            dfs(board, board.size()-1, j);
        }

        for(int i = 0; i<board.size(); ++i){
            for(int j = 0; j<board[0].size(); ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'Y'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};

#else

class Solution130 {
private:
    vector<int> parent;
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        parent = vector<int>(m * n + 1);
        int dummyParent = m * n;
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    parent[i * n + j] = dummyParent;
                }else{
                     parent[i * n + j] = i * n + j;
                }
            }
        }
        parent[m*n] = dummyParent;

        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        for(int i = 0; i<board.size(); ++i){
            for(int j = 0; j<n; ++j){
                if(board[i][j] != 'O'){
                    continue;
                }
                for(int k = 0; k<4; ++k){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size()){
                        if(board[x][y] == 'O'){
                            int parent_a = find(i * n + j);
                            int parent_b = find(x * n + y);
                            if(parent_a != parent_b)
                                parent[parent_b] = parent_a;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j<n; ++j){
                if(board[i][j] != 'O'){
                    continue;
                }
                if(find(i * n + j) != find(dummyParent)){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

#endif

void test130(){
    Solution130 solution;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    solution.solve(board);
    for(auto row: board){
        for(auto c: row){
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;

    //[["X","X","X","O","X","O","X"],["X","O","X","O","X","O","O"],["X","X","X","X","X","X","O"],["X","X","X","X","O","X","O"],["X","X","X","X","X","X","O"],["X","X","X","X","X","X","X"],["O","X","X","O","O","O","X"]]
    board = {
        {'X', 'X', 'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'O', 'X', 'O', 'O'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'O'},
        {'X', 'X', 'X', 'X', 'O', 'X', 'O'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'O'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X'},
        {'O', 'X', 'X', 'O', 'O', 'O', 'X'}
    };
    solution.solve(board);
    for(auto row: board){
        for(auto c: row){
            cout << c << " ";
        }
        cout << endl;
    }

    // [["O","O","O","O","X","X"],["O","O","O","O","O","O"],["O","X","O","X","O","O"],["O","X","O","O","X","O"],["O","X","O","X","O","O"],["O","X","O","O","O","O"]]
    board = {
        {'O', 'O', 'O', 'O', 'X', 'X'},
        {'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'O'},
        {'O', 'X', 'O', 'O', 'O', 'O'}
    };
    solution.solve(board);
    for(auto row: board){
        for(auto c: row){
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;



    board = {
        {'X'}
    };
    solution.solve(board);
    for(auto row: board){
        for(auto c: row){
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;


    board = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'X', 'O', 'X'}
    };
    solution.solve(board);
    for(auto row: board){
        for(auto c: row){
            cout << c << " ";
        }
        cout << endl;
    }
}

#endif // !_GRAPH_DFS_LEETCODE130_H_