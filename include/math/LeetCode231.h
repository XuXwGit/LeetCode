/*
231. 2 的幂
已解答

给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。

如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。
*/

#ifndef _MATH_LEETCODE231_H_
#define _MATH_LEETCODE231_H_

class Solution231 {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n&(n-1)) == 0;
        // return n > 0 && (n&(-n)) == n;
    }
};

#endif // _MATH_LEETCODE231_H_