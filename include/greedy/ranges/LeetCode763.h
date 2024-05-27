/*
763. 划分字母区间
已解答
中等
相关标签
相关企业
提示
给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。

注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。

返回一个表示每个字符串片段的长度的列表。



示例 1：
输入：s = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。
示例 2：

输入：s = "eccbbbbdec"
输出：[10]


提示：

1 <= s.length <= 500
s 仅由小写英文字母组成
*/

#ifndef _GREEDY_LEETCODE763_H_
#define _GREEDY_LEETCODE763_H_

class Solution763
{
private:
    vector<int> mergeRanges(vector<vector<int>> &ranges)
    {
        sort(ranges.begin(), ranges.end(), [](vector<int> &le, vector<int> &rh)
             {
            if(le[1] == rh[1]){
                return le[0] < rh[0];
            }else{
                return le[1] < rh[1];
            } });

        vector<vector<int>> res;
        res.push_back(ranges[0]);

        for (int i = 1; i < ranges.size(); ++i)
        {
            if (ranges[i][0] > res.back()[1])
            {
                res.push_back(ranges[i]);
            }
            else if (ranges[i][0] > res.back()[0])
            {
                res.back()[1] = ranges[i][1];
            }
            else
            {
                while (!res.empty() && res.back()[0] >= ranges[i][0])
                {
                    res.pop_back();
                }

                if (res.empty() || res.back()[1] < ranges[i][0])
                {
                    res.push_back(ranges[i]);
                }
                else
                {
                    res.back()[1] = ranges[i][1];
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < res.size(); ++i)
        {
            result.push_back(res[i][1] - res[i][0] + 1);
        }

        return result;
    }

public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<int, vector<int>> char_ranges;
        for (int i = 0; i < s.size(); ++i)
        {
            if (char_ranges.count(s[i]))
            {
                char_ranges[s[i]][1] = i;
            }
            else
            {
                char_ranges[s[i]] = {i, i};
            }
        }

        vector<vector<int>> ranges;
        for (auto [ch, x] : char_ranges)
        {
            ranges.push_back(x);
        }

        return mergeRanges(ranges);
    }
};

void test763()
{
    string s = "ababcbacadefegdehijhklij";
    Solution763 sl;
    vector<int> res = sl.partitionLabels(s);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

#endif // !_GREEDY_LEETCODE763_H_