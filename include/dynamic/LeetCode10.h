/*
10. 正则表达式匹配
困难

给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配"零个"或多个前面的那一个元素
Note: 要考虑0个前置字符
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
*/

#ifndef _LEETCODE10_H_
#define _LEETCODE10_H_


class Solution10 {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        s = " "+ s;
        p = " "+ p;

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        // set bounds
        dp[0][0] = true;
        for(int i = 0; i<=m; ++i){
            for(int j = 1; j<=n; ++j){
                if(p[j] == '*'){
                    // 1. zero pre-char
                    // 2. >=1 pre-char
                    dp[i][j] = dp[i][j-2] || (i && dp[i-1][j] && (j>1 && (p[j-1] == s[i] || p[j-1] == '.')));
                }else if(i && p[j] != '*'){
                    dp[i][j] = dp[i-1][j-1] && (s[i] == p[j] || p[j] == '.');
                }
            }
        }

        return dp[m][n];
    }
};


void test10(){
    Solution10 s;
    cout << s.isMatch("aaa", "aaaaa") << endl;
    cout << s.isMatch("aa", "a*") << endl;
    cout << s.isMatch("ab", ".*") << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;
    cout << s.isMatch("mississippi", "mis*is*p*.") << endl;
}

#endif // !_LEETCODE10_H_