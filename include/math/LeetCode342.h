/*
342. 4的幂
已解答

给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4^x
*/


#ifndef _LEETCODE342_H_
#define _LEETCODE342_H_

class Solution {
private:
    bool method1(int n){
        while(n != 1){
            if(n%4 != 0){
                return false;
            }
            n = n/4;
        }

        return n == 1;
    }
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n&(n-1)) == 0 && n
    }
};


#endif // _LEETCODE342_H_
