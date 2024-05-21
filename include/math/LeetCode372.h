/*

372. 超级次方
已解答
中等
相关标签
相关企业
你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。

示例 4：

输入：a = 2147483647, b = [2,0,0]
输出：1198
*/

#ifndef _MATH_LEETCODE372_H_
#define _MATH_LEETCODE372_H_

class Solution372 {
private:
    int MOD = 1337;
    int quickPow(int a, int n){
        int res  = 1;
        int ans = a%MOD;
        while(n){
            if(n&1){
                res = (res * ans)%MOD;
            }
            ans = (ans*ans)%MOD;
            n >>=1;
        }

        return res;
    }

    int dfs(int a, vector<int>& b, int len){
        if(len == 0){
            return 1;
        }

        return (quickPow(dfs(a, b, len-1), 10) * quickPow(a, b[len-1]))%MOD;
    }
public:
    int superPow(int a, vector<int>& b) {
        return dfs(a, b, b.size());
    }
};


void test372(){
    Solution372 solution372;
    vector<int> b = {1, 0};
    cout << solution372.superPow(2, b) << endl;

    b = {4,3,3,8,5,2};
    cout << solution372.superPow(2147483647, b) << endl;
}

#endif // _MATH_LEETCODE372_H_