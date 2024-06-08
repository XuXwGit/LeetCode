/*
2982. 找出出现至少三次的最长特殊子字符串 II
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

3 <= s.length <= 5 * 10^5
s 仅由小写英文字母组成。
*/

#ifndef _LEETCODE_STRING_LEETCODE2982_H_
#define _LEETCODE_STRING_LEETCODE2982_H_

class Solution2982
{
public:
    int maximumLength(string s)
    {
        unordered_map<char, vector<int>> subchars;
        int count = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i > 0 && s[i] != s[i - 1])
            {
                subchars[s[i - 1]].push_back(count);
                count = 0;
            }
            count++;
        }
        subchars[s.back()].push_back(count);

        int maxLen = -1;
        for (auto [ch, x] : subchars)
        {
            sort(x.begin(), x.end(), greater<>());
            x.push_back(0);
            x.push_back(0);
            maxLen = max(maxLen, max({x[0] - 2, min(x[0] - 1, x[1]), x[2]}));
        }

        return maxLen == 0 ? -1 : maxLen;
    }
};

void test2982()
{
    Solution2982 solution2982;
    cout << solution2982.maximumLength("aaaa") << endl;
    cout << solution2982.maximumLength("abcdef") << endl;
    cout << solution2982.maximumLength("abcaba") << endl;
}

#endif // !_LEETCODE_STRING_LEETCODE2982_H_