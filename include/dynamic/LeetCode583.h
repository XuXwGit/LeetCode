/*
583. 两个字符串的删除操作
已解答
中等

给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

每步 可以删除任意一个字符串中的一个字符。
*/


#ifndef _LEETCODE583_H_
#define _LEETCODE583_H_

class Solution583 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        word1 = " "+ word1;
        word2 = " "+ word2;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i<= m; ++i){
            dp[i][0] = i;
        }
        for(int j = 0; j<= n; ++j){
            dp[0][j] = j;
        }
        
        for(int i = 1; i<=m;++i){
            for(int j = 1; j<=n; ++j){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

void test583(){
    Solution583 s;
    cout << s.minDistance("sea", "eat") << endl;
    cout << s.minDistance("leetcode", "etco") << endl;
    cout << s.minDistance("intention", "execution") << endl;
}


#endif // !_LEETCODE583_H_