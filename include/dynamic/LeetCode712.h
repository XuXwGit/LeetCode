/*
712. 两个字符串的最小ASCII删除和

给定两个字符串s1 和 s2，返回 使两个字符串相等所需删除字符的 ASCII 值的最小和 。

*/

#ifndef _LEETCODE712_H_
#define _LEETCODE712_H_

class Solution712 {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        s1 = " " + s1;
        s2 = " " + s2;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 0;
        for(int i = 1; i<=m; ++i){
            dp[i][0] = dp[i-1][0] + (int)s1[i];
        }
        for(int j = 1; j<=n; ++j){
            dp[0][j] = dp[0][j-1] + (int)s2[j];
        }

        for(int i = 1; i<=m; ++i){
            for(int j = 1; j<=n; ++j){
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i][j-1] + (int)s2[j], dp[i-1][j] + (int)s1[i]);
                }
            }
        }

        return dp[m][n];
    }
}; 


void test712(){
    Solution712 s;
    cout << s.minimumDeleteSum("sea", "eat") << endl;
    cout << s.minimumDeleteSum("delete", "leet") << endl;
    cout << s.minimumDeleteSum("delete", "leet") << endl;
}


#endif // !_LEETCODE712_H_