/*
2024.1.31-HW秋招笔试-第一题-找出最可疑的嫌疑人
民警侦办某商场店面盗窃率时，通过人脸识别针对嫌局人讲行编号1-100000。现在民警在监控记录中发现有个嫌疑人在被动店面出现的次数超过了所有嫌疑人总出现次数的一半，请帮助民警尽可能高效的找到该嫌疑人的编号。

解答要求

时间限制:C/C++ 1500ms,其他语言:3000ms

内存限制:C/C++ 32MB, 其他语言:64MB

输入

给定一个嫌疑人的标号数组men，其中1<length(men)<1000，嫌人编号满足1<=men[i]<=100000

输出

返回出现次数超过一半的嫌疑人的编号。如果总次数是偶数，例如4，则需要超过2次即最少3次，如果总次数是奇数，例如5，则需要超过2.5，满足条件最少是3次。若没有嫌疑人满足该条件，返回0

样例1

输入

1,2,3,2,2
输出

2
解释

第一行是嫌疑人出现记录，代表1号和3号嫌疑人出现一次，2号嫌疑人出现3次

因为2号嫌疑人出现3次，超过5次的一半，因此2号嫌疑人即为需要寻找的编号，输出2

样例2

输入

1,1,2,2,3,3
输出

0
解释

第一行是嫌疑人出现记录，代表1号、2号和3号嫌疑人各出现2次因为各个嫌疑人均只出现2次，未超过6次的一半，因此没有嫌疑人满足要求，输出0
*/

#ifndef _EXAMINATION_HUAWEI_0131_01_H_
#define _EXAMINATION_HUAWEI_0131_01_H_

#include <bits/stdc++.h>
#include <functional>

using namespace std;

vector<int> split(string s)
{
    int left = 0;
    int len = 0;
    vector<int> res;

    while (left + len < (int)s.size())
    {
        if (s[left + len] == ',')
        {
            res.push_back(stoi(s.substr(left, len)));
            left = left + len + 1;
            len = 0;
        }
        else
        {
            len++;
        }
    }
    res.push_back(stoi(s.substr(left, len)));

    return res;
}

void test_0131_01()
{
    string s = "1,1,2,2,3,3";
    // cin >> s;
    vector<int> nums = split(s);
    map<int, int> counts;
    for (int x : nums)
    {
        // cout << x << ",";
        counts[x]++;
    }
    // cout << endl;

    int max = 0;
    int men = 0;
    for (auto x : counts)
    {
        // cout << x.first << ":" << x.second << endl;
        if (x.second > max)
        {
            max = x.second;
            men = x.first;
        }
    }

    if (max > (int)nums.size() / 2)
    {
        cout << men;
    }
    else
    {
        cout << 0;
    }
}

#endif // !_EXAMINATION_HUAWEI_0131_01_H_