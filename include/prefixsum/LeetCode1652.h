/*
1652. 拆炸弹
已解答
简单
相关标签
相关企业
提示
你有一个炸弹需要拆除，时间紧迫！你的情报员会给你一个长度为 n 的 循环 数组 code 以及一个密钥 k 。

为了获得正确的密码，你需要替换掉每一个数字。所有数字会 同时 被替换。

如果 k > 0 ，将第 i 个数字用 接下来 k 个数字之和替换。
如果 k < 0 ，将第 i 个数字用 之前 k 个数字之和替换。
如果 k == 0 ，将第 i 个数字用 0 替换。
由于 code 是循环的， code[n-1] 下一个元素是 code[0] ，且 code[0] 前一个元素是 code[n-1] 。

给你 循环 数组 code 和整数密钥 k ，请你返回解密后的结果来拆除炸弹！
*/

#ifndef _LEETCODE1652_H
#define _LEETCODE1652_H

class Solution1652 {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> presum(2*n, 0);
        presum[0] = code[0];
        for(int i = 1; i<presum.size(); ++i){
            presum[i] = presum[i-1] + code[(i)%n];
        }
        vector<int> res(n, 0);
        for(int i = 0; i<n; ++i){
            if(k >= 0){
                res[i] = presum[i + k] - presum[i];
            }else{
                res[i] = presum[i+n-1] - presum[i+n+k-1];
            }
        }

        return res;
    }
};

void test1652(){
    Solution1652 sol;
    vector<int> code = {5,7,1,4};
    int k = 3;
    vector<int> res = sol.decrypt(code, k);
    for(auto& r : res){
        cout << r << " ";
    }
    cout << endl;
}

#endif // _LEETCODE1652_H