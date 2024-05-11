/*
3. 无重复字符的最长子串
已解答
中等
相关标签
相关企业
给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串的长度。
*/

#ifndef _SLIDINGWINDOW_LEETCODE3_H_
#define _SLIDINGWINDOW_LEETCODE3_H_

class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0;
        int len = 0;
        set<char> chars;
        while(left + len < s.size()){
            if(chars.count(s[left + len])){
                chars.erase(s[left]);
                len --;
                left ++;
            }else{
                chars.insert(s[left + len]);
                len ++;
                res = max(res, len);
            }
        }

        return res;
    }
};

void test3(){
    string s = "abcabcbb";
    Solution3 solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
}

#endif // !_SLIDINGWINDOW_LEETCODE3_H_
