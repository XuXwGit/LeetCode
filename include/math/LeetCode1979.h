/*

1979. 找出数组的最大公约数
已解答
简单
相关标签
相关企业
提示
给你一个整数数组 nums ，返回数组中最大数和最小数的 最大公约数 。

两个数的 最大公约数 是能够被两个数整除的最大正整数。

*/

#ifndef _LEETCODE_MATH_LEETCODE_1979_H_
#define _LEETCODE_MATH_LEETCODE_1979_H_

#include <algorithm>

class Solution1979 {
private:
// C++ has gcd function
    int gcd(int a, int b){
         if(b == 0){
             return 0;
         }
         if(a < b){
             return gcd(b, a);
         }
         return a%b ? gcd(b, a%b) : b;
    }
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return gcd(nums.back(), nums.front());
    }
};

void test1979(){
    Solution1979 solution;
    vector<int> nums = {2, 5, 6, 9, 10};
    cout << solution.findGCD(nums) << endl;
    nums = {7, 5, 6, 8, 3};
    cout << solution.findGCD(nums) << endl;
    nums = {3, 3};
    cout << solution.findGCD(nums) << endl;
}

#endif // !_LEETCODE_MATH_LEETCODE_1979_H_