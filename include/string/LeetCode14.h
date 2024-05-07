/*
14. 最长公共前缀
已解答
简单
相关标签
相关企业
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
*/
#ifndef _STRING_LEETCODE14_H
#define _STRING_LEETCODE14_H

class Solution14 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        int min_len = INT_MAX;
        for(int i = 0; i<strs.size(); ++i){
            min_len = min_len < strs[i].size()? min_len : strs[i].size();
        }

        if(min_len == 0){
            return res;
        }

        bool flag = true;
        while(flag){
            char curr = strs[0][res.size()];
            for(int i = 0; i<strs.size(); ++i){
                if(strs[i][res.size()] != curr){
                    flag = false;
                    break;
                }
            }
            if(flag){
                res.push_back(curr);
            }
            if(res.size() == min_len){
                flag = false;
            }
        }
        
        return res;
    }
};

void test14(){
    Solution14 sol;
    vector<string> strs = {"flower","flow","flight"};
    cout << sol.longestCommonPrefix(strs) << endl;
}

#endif // _STRING_LEETCODE14_H