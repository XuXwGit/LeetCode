/*
1017. 负二进制转换

给你一个整数 n ，以二进制字符串的形式返回该整数的 负二进制（base -2）表示。

注意，除非字符串就是 "0"，否则返回的字符串中不能含有前导零。
*/

#ifndef _LEETCODE_MATH_LEETCODE_1017_H_
#define _LEETCODE_MATH_LEETCODE_1017_H_


class Solution1017 {
public:
    string baseNeg2(int n) {
        if(n == 0){
            return "0";
        }
        
        string res = "";

        while(n){
            if(n%(-2) == 1){
                res += "1";
                n /= (-2);
            }else if(n%(-2) == 0){
                res += "0";
                n /= (-2);
            }else if(n%(-2) == -1){
                res += "1";
                n /= (-2);
                n += 1;
            }
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};

void test1017(){
    Solution1017 solution;
    int n = 2;
    cout << solution.baseNeg2(n) << endl;
    n = 3;
    cout << solution.baseNeg2(n) << endl;
}

#endif // _LEETCODE_MATH_LEETCODE_1017_H_