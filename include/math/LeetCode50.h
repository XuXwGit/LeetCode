/*
50. Pow(x, n)

实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）。
*/

#ifndef _MATH_LEETCODE50_H_
#define _MATH_LEETCODE50_H_

class Solution50 {
public:
    double myPow(double x, int n) {
        if(n < 0){
            return myPow(1.0/x, abs(n));
        }
        double res = 1.0;
        double a = x;
        while(n){
            if(n & 1){
                res = res * a;
            }
            a *= a;
            n >>= 1;
        }

        return res;
    }
};



#endif // _MATH_LEETCODE50_H_