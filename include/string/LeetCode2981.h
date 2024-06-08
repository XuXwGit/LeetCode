/*
2981. 找出出现至少三次的最长特殊子字符串 I
已解答
中等
相关标签
相关企业
提示
给你一个仅由小写英文字母组成的字符串 s 。

如果一个字符串仅由单一字符组成，那么它被称为 特殊 字符串。例如，字符串 "abc" 不是特殊字符串，而字符串 "ddd"、"zz" 和 "f" 是特殊字符串。

返回在 s 中出现 至少三次 的 最长特殊子字符串 的长度，如果不存在出现至少三次的特殊子字符串，则返回 -1 。

子字符串 是字符串中的一个连续 非空 字符序列。



示例 1：

输入：s = "aaaa"
输出：2
解释：出现三次的最长特殊子字符串是 "aa" ：子字符串 "aaaa"、"aaaa" 和 "aaaa"。
可以证明最大长度是 2 。
示例 2：

输入：s = "abcdef"
输出：-1
解释：不存在出现至少三次的特殊子字符串。因此返回 -1 。
示例 3：

输入：s = "abcaba"
输出：1
解释：出现三次的最长特殊子字符串是 "a" ：子字符串 "abcaba"、"abcaba" 和 "abcaba"。
可以证明最大长度是 1 。


提示：

3 <= s.length <= 50
s 仅由小写英文字母组成。
*/

#ifndef __INCLUDE_STRING_LEETCODE2981__
#define __INCLUDE_STRING_LEETCODE2981__

class Solution2981
{
public:
    // int maximumLength(string s) {
    //     unordered_map<string, int> substrs;
    //     for(int i = 0; i<s.size(); ++i){
    //         for(int len = 1; i + len - 1 < s.size(); ++len){
    //             if(s[i + len -1] != s[i]){
    //                 break;
    //             }
    //             substrs[s.substr(i, len)]++;;
    //         }
    //     }

    //     int maxLen = -1;
    //     for(auto x: substrs){
    //         if(x.second >= 3){
    //             maxLen = max(maxLen, (int)x.first.size());
    //         }
    //     }

    //     return maxLen;
    // }

    int maximumLength(string s)
    {
        unordered_map<char, vector<int>> substrs;
        int count = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i > 0 && s[i] != s[i - 1])
            {
                substrs[s[i - 1]].push_back(count);
                count = 0;
            }
            count++;
        }
        substrs[s.back()].push_back(count);

        int maxLen = -1;

        for (auto [ch, x] : substrs)
        {
            sort(x.begin(), x.end(), greater<int>());
            x.push_back(0);
            x.push_back(0);
            maxLen = max({maxLen, x[0] - 2, min(x[0] - 1, x[1]), x[2]});
        }

        return maxLen == 0 ? -1 : maxLen;
    }
};

void test2981()
{
    Solution2981 solution2981;
    cout << solution2981.maximumLength("aaaa") << endl;
    cout << solution2981.maximumLength("abcdef") << endl;
    cout << solution2981.maximumLength("abcaba") << endl;
    cout << solution2981.maximumLength("abcccccdddd") << endl;
}

#endif // __INCLUDE_STRING_LEETCODE2981__