/*
28. 找出字符串中第一个匹配项的下标
已解答
简单
相关标签
相关企业
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
*/

// KMP 算法

#ifndef _STRING_LEETCODE28_H_
#define _STRING_LEETCODE28_H_

class Solution28 {
public:
    int strStr(string haystack, string needle) {
        vector<int> next(needle.size());
        next[0] = 0;
        int prefix_len = 0;
        int i = 1;
        while(i < needle.size()){
            if(needle[prefix_len] == needle[i]){
                prefix_len += 1;
                next[i] = prefix_len;
                ++i;
            }else{
                if(prefix_len == 0){
                    next[i] = 0;
                    ++i;
                }else{
                    prefix_len = next[prefix_len - 1];
                }
            }
        }

        int l1 = 0;
        int l2 = 0;
        while(l1 < haystack.size()){
            if(haystack[l1] == needle[l2]){
                l1 ++;
                l2 ++;
            }else if(l2 > 0){
                l2 = next[l2 - 1];
            }else if(l2 == 0){
                l1 ++;
            }

            if(l2 == needle.size()){
                return l1 - l2;
            }
        }

        return -1;
    }
};

void test28(){
    Solution28 solution;
    string haystack = "hello";
    string needle = "ll";
    cout << solution.strStr(haystack, needle) << endl;
}

#endif // !_STRING_LEETCODE28_H_