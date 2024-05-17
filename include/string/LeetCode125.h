/*
125. 验证回文串
简单
相关标签
相关企业
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

字母和数字都属于字母数字字符。

给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
*/

#ifndef _STRING_LEETCODE125_H
#define _STRING_LEETCODE125_H

class Solution125 {
public:
    bool isPalindrome(string s) {
        string str ;
        for(int i = 0; i<s.size(); ++i){
            if(s[i]>= 'A' && s[i] <= 'Z'){
                str.push_back(char('a' + (s[i] - 'A')));
            }else if((s[i]>= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){    
                str.push_back(s[i]);
            }
        }
        string rever_str = str;
        reverse(str.begin(), str.end());
        return str ==  rever_str;
    }
};

void test125() {
    Solution125 sol;
    string s = "0P";
    cout << sol.isPalindrome(s) << endl;
}
#endif  // !_STRING_LEETCODE125_H