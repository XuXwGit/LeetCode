/*
44. 通配符匹配
困难

给你一个输入字符串 (s) 和一个字符模式 (p) ，请你实现一个支持 '?' 和 '*' 匹配规则的通配符匹配：
'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符序列（包括空字符序列）。
判定匹配成功的充要条件是：字符模式必须能够 完全匹配 输入字符串（而不是部分匹配）。
*/

#ifndef _LEETCODE44_H_
#define _LEETCODE44_H_

class Solution44 {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> df(m+1, vector<bool>(n+1, false));
        df[0][0] = true;
        for(int i = 1; i<=m; ++i){
            df[i][0] = (df[i-1][0] && p[i-1] == '*');
        }
        for(int j = 1; j<=n; ++j){
            df[0][j] = false;
        }
        
        for(int i = 1; i<=m; ++i){
            for(int j = 1; j<=n; ++j){
                if(p[i-1] == '*'){
                    df[i][j] = df[i-1][j] || df[i][j-1];
                }else if(p[i-1] == '?'){
                    df[i][j] = df[i-1][j-1];
                }else{
                    df[i][j] = df[i-1][j-1] && p[i-1] == s[j-1];
                }
            }
        }

        return df[m][n];
    }
};

void test44(){
    Solution44 s;
    // "abefcdgiescdfimde"
    // "ab*cd?i*de"
    cout << s.isMatch("abefcdgiescdfimde", "ab*cd?i*de") << endl;
}

#endif // !_LEETCODE44_H_