/*
1. 获取公共链表片段
给定两个链表，获取两者中相同节点值的最大连续片段。如果没有公共片段，返回-1。

解答要求

时间限制: C/C++ 1000ms,其他语言: 2000ms内存限制: C/C++ 256MB, 其他语言: 512MB

输入

第一行表示链表1，第二行表示链表2，每条链表长度不超过20个元素，链表不会为空。

输出

公共链表片段

样例1

输入

1 2 2 3 9 1 5
9 2 2 3 6 8
输出

2 2 3
*/

#ifndef _EXAMINATION_0522_HUAWEI_01_LIST_H_
#define _EXAMINATION_0522_HUAWEI_01_LIST_H_

class Solution_0522_HW_01
{
public:
    vector<int> getCommonList(vector<int> &list1, vector<int> &list2)
    {
        int n = list1.size();
        int m = list2.size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<vector<int>> start(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (list1[i] != list2[j])
                {
                    dp[i][j] = 0;
                    start[i][j] = -1;
                }
                else
                {
                    if (i > 0 && j > 0 && list1[i - 1] == list2[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        start[i][j] = start[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = 1;
                        start[i][j] = i;
                    }
                }
            }
        }

        int max_len = 0;
        int start_idx = -1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (dp[i][j] > max_len)
                {
                    max_len = dp[i][j];
                    start_idx = start[i][j];
                }
            }
        }

        vector<int> res;
        for (int i = start_idx; i < start_idx + max_len; ++i)
        {
            res.push_back(list1[i]);
        }

        return res;
    }
};

void test_0522_HW_01()
{
    std::cout << "0522 Huawei 01 List" << std::endl;
    vector<int> list1 = {1, 2, 2, 3, 9, 1, 5};
    vector<int> list2 = {9, 2, 3, 9, 6, 8};
    Solution_0522_HW_01 sln;
    vector<int> res = sln.getCommonList(list1, list2);
    for (auto &num : res)
    {
        std::cout << num << " ";
    }
}

#endif // _EXAMINATION_0522_HUAWEI_01_LIST_H_