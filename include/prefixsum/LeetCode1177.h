/*
1177. 构建回文串检测
已解答
中等
相关标签
相关企业
提示
给你一个字符串 s，请你对 s 的子串进行检测。

每次检测，待检子串都可以表示为 queries[i] = [left, right, k]。我们可以 重新排列 子串 s[left], ..., s[right]，并从中选择 最多 k 项替换成任何小写英文字母。 

如果在上述检测过程中，子串可以变成回文形式的字符串，那么检测结果为 true，否则结果为 false。

返回答案数组 answer[]，其中 answer[i] 是第 i 个待检子串 queries[i] 的检测结果。

注意：在替换时，子串中的每个字母都必须作为 独立的 项进行计数，也就是说，如果 s[left..right] = "aaa" 且 k = 2，我们只能替换其中的两个字母。（另外，任何检测都不会修改原始字符串 s，可以认为每次检测都是独立的）
*/

/*
输入：s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
输出：[true,false,false,true,true]
解释：
queries[0] : 子串 = "d"，回文。
queries[1] : 子串 = "bc"，不是回文。
queries[2] : 子串 = "abcd"，只替换 1 个字符是变不成回文串的。
queries[3] : 子串 = "abcd"，可以变成回文的 "abba"。 也可以变成 "baab"，先重新排序变成 "bacd"，然后把 "cd" 替换为 "ab"。
queries[4] : 子串 = "abcda"，可以变成回文的 "abcba"。
*/

#ifndef _PREFIXSUM_LEETCODE1177_H_
#define _PREFIXSUM_LEETCODE1177_H_

class Solution1177 {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> count_chars(s.size()+1, vector<int>(26, 0));

        for(int i = 0; i<s.size(); ++i){
            count_chars[i+1] = count_chars[i];
            count_chars[i+1][s[i] - 'a'] ++;
        }

        vector<bool> res(queries.size(), false);

        for(int i = 0; i< queries.size(); ++i){
            int left = queries[i][0];
            int right = queries[i][1];
            int k = queries[i][2];

            int count_off = 0;
            for(int j = 0; j<26; ++j){
                int num = count_chars[right+1][j] - count_chars[left][j];
                if(num % 2){
                    count_off ++;
                }
            }

            if(count_off/2 <= k){
                res[i] = true;
            }
        }

        return res;
    }
};


void test1177(){
    Solution1177 solution1177;
    string s = "abcda";
    vector<vector<int>> queries = {{3,3,0},{1,2,0},{0,3,1},{0,3,2},{0,4,1}};
    vector<bool> res = solution1177.canMakePaliQueries(s, queries);
    for(auto r: res){
        cout << r << " ";
    }
    cout << endl;
}

#endif // _PREFIXSUM_LEETCODE1177_H_
