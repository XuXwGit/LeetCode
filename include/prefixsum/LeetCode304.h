#ifndef _LEETCODE_304_H_
#define _LEETCODE_304_H_

class NumMatrix {
private:
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix): sums(matrix.size()+1, vector<int>(matrix[0].size()+1,0)) {
        for(int i = 0; i<matrix.size(); ++i){
            for(int j = 0; j<matrix[0].size(); ++j){
                sums[i+1][j+1] = sums[i][j+1] + sums[i+1][j] - sums[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] + sums[row1][col1] - sums[row2+1][col1] - sums[row1][col2+1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
/*
["NumMatrix","sumRegion","sumRegion","sumRegion"]
[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
*/
void test304(){
    vector<vector<int>> matrix = {{3,0,1,4,2},
                                  {5,6,3,2,1},
                                  {1,2,0,1,5},
                                  {4,1,0,1,7},
                                  {1,0,3,0,5}};
    NumMatrix* obj = new NumMatrix(matrix);
    cout << obj->sumRegion(2,1,4,3) << endl;
    cout << obj->sumRegion(1,1,2,2) << endl;
    cout << obj->sumRegion(1,2,2,4) << endl;
    delete obj;
}

#endif // _LEETCODE_304_H_