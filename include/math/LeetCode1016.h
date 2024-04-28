/*
1016. 子串能表示从 1 到 N 数字的二进制串

给定一个二进制字符串 s 和一个正整数 n，如果对于 [1, n] 范围内的每个整数，其二进制表示都是 s 的 子字符串 ，就返回 true，否则返回 false 。

子字符串 是字符串中连续的字符序列。
*/

#ifndef _LEETCODE_MATH_LEETCODE_1016_H_
#define _LEETCODE_MATH_LEETCODE_1016_H_


class Solution1016 {
public:
    bool queryString(string s, int n) {
        reverse(s.begin(), s.end());

        int k = 0;
        int num = n;
        while(num){
            k ++;
            num /= 2;
        }

        set<int> nums;
        num = 0;
        int temp = 1;
        int left = 0;
        int right = 0;
        for(; right < k-1; ++right){
            num += temp * (s[right] - '0');
            temp *= 2;
        }
        right --;
        while(right < s.size()){
            if(num <= n && num >= temp/2)  nums.insert(num);
            right ++;
            if(right < s.size()){
                num += temp * (s[right] - '0');
                if(num <= n && num >= temp)  nums.insert(num);
            }
            left ++;
            num /= 2;
        }

        if(s.size() == 1){
            return s == "1";
        }

        return nums.size() == (n - temp/2 + 1);
    }
};


void test1016(){
    Solution1016 solution;
    string s = "0110";
    int n = 3;
    cout << (solution.queryString(s, n) ? "true" : "false") << endl;
    s = "1";
    n = 1;
    cout << (solution.queryString(s, n) ? "true" : "false") << endl;
    n = 4;
    cout << (solution.queryString(s, n) ? "true" : "false") << endl;
    s = "110101011011000011011111000000";
    n = 15;
    cout << (solution.queryString(s, n) ? "true" : "false") << endl;
}

#endif // _LEETCODE_MATH_LEETCODE_1016_H_