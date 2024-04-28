/*
204. 计数质数
已解答
中等

给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。
*/

#ifndef _LEETCODE_MATH_LEETCODE_204_H_
#define _LEETCODE_MATH_LEETCODE_204_H_


class Solution204 {
// private:
    // bool isPrimeNum(int n){
    //     if(n < 2){
    //         return false;
    //     }

    //     for(int i = 2; i < n; ++i){
    //         if(n % i == 0){
    //             return false;
    //         }
    //     }

    //     return true;
    // }
    // int method2(int n){
    //     if(n <= 1){
    //         return 0;
    //     }
        
    //     vector<bool> flags(n, true);
    //     int count = 0;
    //     for(int i = 2; i<n; ++i){
    //         if(flags[i]){
    //             count ++;
    //             for(int j = 2*i; j <= n; j += i){
    //                 flags[j] = false;
    //             }
    //         }
    //     }

    //     return count;
    // }
public:
    int countPrimes(int n) {
        if(n <= 1){
            return 0;
        }
        
        vector<bool> flags(n, true);
        vector<int> primes;
        for(int i = 2; i<n; ++i){
            if(flags[i]){
                primes.push_back(i);
            }
            for(int j = 0; i * primes[j] < n ;  ++j){
                flags[i * primes[j]] = false;
                if(i % primes[j] == 0){
                    break;
                }
            }
        }

        return primes.size();
    }
};


void test204(){
    Solution204 solution;
    cout << solution.countPrimes(10) << endl;
    cout << solution.countPrimes(0) << endl;
    cout << solution.countPrimes(1) << endl;
    cout << solution.countPrimes(2) << endl;
    cout << solution.countPrimes(3) << endl;
    cout << solution.countPrimes(4) << endl;
    cout << solution.countPrimes(5) << endl;
    cout << solution.countPrimes(6) << endl;
    cout << solution.countPrimes(7) << endl;
    cout << solution.countPrimes(8) << endl;
    cout << solution.countPrimes(9) << endl;
}

#endif // !_LEETCODE_MATH_LEETCODE_204_H_