/*
2521. 数组乘积中的不同质因数数目

给你一个正整数数组 nums ，对 nums 所有元素求积之后，找出并返回乘积中 不同质因数 的数目。

注意：

质数 是指大于 1 且仅能被 1 及自身整除的数字。
如果 val2 / val1 是一个整数，则整数 val1 是另一个整数 val2 的一个因数。
*/

#ifndef _LEETCODE_MATH_LEETCODE_2521_H_
#define _LEETCODE_MATH_LEETCODE_2521_H_


class Solution2521 {
private:
    void decomposition(int n, set<int>& factors){
        if(n < 1){
            return;
        }

        for(int i = 2; i <= n/i; ++i){
            if(n % i == 0){
                factors.insert(i);
                while(n%i == 0){
                    n /= i;
                }
            }
        }

        if(n > 1)   factors.insert(n);
    }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> factors;
        for(int i = 0; i<nums.size(); ++i){
            decomposition(nums[i], factors);
        }

        return factors.size();
    }
};


void test2521(){
    Solution2521 solution;
    vector<int> nums = {2, 3, 6};
    cout << solution.distinctPrimeFactors(nums) << endl;
    nums = {2, 3, 4};
    cout << solution.distinctPrimeFactors(nums) << endl;
    nums = {2, 3, 4, 5, 6};
    cout << solution.distinctPrimeFactors(nums) << endl;
    nums = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << solution.distinctPrimeFactors(nums) << endl;
    nums = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cout << solution.distinctPrimeFactors(nums) << endl;
    nums = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    cout << solution.distinctPrimeFactors(nums) << endl;
    nums = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    cout << solution.distinctPrimeFactors(nums) << endl;
    nums = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    cout << solution.distinctPrimeFactors(nums) << endl;
    nums = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    cout << solution.distinctPrimeFactors(nums) << endl;
    nums = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
}

#endif // !_LEETCODE_MATH_LEETCODE_2521_H_