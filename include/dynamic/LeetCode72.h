/*
72. 编辑距离
已解答
中等

给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 
*/

#ifndef _LEETCODE72_H_
#define _LEETCODE72_H_

class Solution72 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        word1 = " " + word1;
        word2 = " " + word2;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i<= m; ++i){
            dp[i][0] = i;
        }
        for(int j = 0; j<= n; ++j){
            dp[0][j] = j;
        }

        for(int i = 1; i<= m; ++i){
            for(int j = 1; j<=n; ++j){
                if(word1[i] == word2[j]){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j] + 1, dp[i][j-1] + 1));
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }

        return dp[m][n];
    }
};


void test72(){
    Solution72 s;
    cout << s.minDistance("horse", "ros") << endl;
    cout << s.minDistance("intention", "execution") << endl;
}

#endif // !_LEETCODE72_H_