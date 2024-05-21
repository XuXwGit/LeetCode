#ifndef _FOUR_0519_02_H_
#define _FOUR_0519_02_H_


void dfs(int i, int j, int count, vector<string>& grad, vector<vector<int>>& dp, vector<vector<bool>>& visited, int h){
    int n = dp.size();
    int m = dp[0].size();

    if(i == n || i < 0 || j == m || j < 0){
        return;
    }

    int res = h;
    if(grad[i][j] == '*'){
        return;
    }
    else if(grad[i][j] >= '1' && grad[i][j] <= '9'){
        res -= grad[i][j] - '0';
    }

    if(res < 0){
        return;
    }else{
        dp[i][j] = min(dp[i][j], count);
    }

    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for(int k = 0; k<4; ++k){
        int x = i + direction[k][0];
        int y = j + direction[k][1];
        if(x >= 0 && x< n && y >= 0 && y < m && !visited[x][y] && res >= 0){
            visited[x][y] = true;
            dfs(x, y, count + 1, grad, dp, visited, res);
            visited[x][y] = false;
        }
    }
}


int minCost(vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    dp[0][0] = 0;
    visited[0][0] = true;
    dfs(0, 0, 0, grid, dp, visited, 0);
    return dp[n-1][m-1];
}


void test0519(){
    cout << "==== test0519 ====" << endl;
    vector<string> grid = {"*1","1*"};
    cout << minCost(grid) << endl;
}


#endif // _FOUR_0519_02_H_