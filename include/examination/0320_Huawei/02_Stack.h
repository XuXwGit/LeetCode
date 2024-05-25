/*
2024.3.20-HW-第二题-塔子哥的积木塔
问题描述
塔子哥在玩积木塔游戏。他有一系列的积木块，每块上标有一个正整数。他按照特定的规则堆积这些积木块：每次塔子哥添加一块新的积木时，如果这块积木上的数字与塔顶的积木数字相同，他会取下两块积木，将上面的数字相加后乘以二，然后放回一块新的积木。此外，如果塔顶的积木数字等于下面连续几块积木数字之和，他同样会取下这些积木，进行相同的操作。如果这两个条件都不符合，他就会简单地将新的积木放在塔顶。现在，塔子哥按照一定顺序添加了一系列的积木，请你计算游戏结束后积木塔各块上的数字。

输入格式
第一行输入为一个由空格分隔的正整数序列，表示塔子哥按顺序添加到积木塔中的积木块上的数字。

输出格式
输出为一个由空格分隔的正整数序列，从左到右依次表示游戏结束后从塔顶到塔底的积木块上的数字。

样例输入
55 66 121 5 5
样例输出
10 242
评测数据与规模
每个正整数的范围为1 到2^31 −1。正整数的个数范围为1 到1000。
*/

#ifndef _EXAMINATION_HUAWEI_0320_02_H_
#define _EXAMINATION_HUAWEI_0320_02_H_

#include <bits/stdc++.h>
#include <vector>

using namespace std;

void solution_HW_0320_02(vector<int> &nums)
{
    vector<int> res;

    for (int i = 0; i < nums.size(); ++i)
    {
        int sum = 0;
        int j = res.size() - 1;
        bool flag = false;
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            int sum = 0;
            int j = res.size() - 1;
            bool flag = false;
            for (j = (int)res.size() - 1; j >= 0; j--)
            {
                sum += res[j];
                if (sum == nums[i])
                {
                    flag = true;
                    break;
                }
                else if (sum > nums[i])
                {
                    break;
                }
            }
            if (flag)
            {
                while ((int)res.size() > j)
                {
                    res.pop_back();
                }
                nums[i] *= 2;
                i--;
            }
            else
            {
                res.push_back(nums[i]);
            }
        }

        for (int i = res.size() - 1; i >= 0; --i)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}

    void test_0320_02()
    {
        vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        solution_HW_0320_02(nums);
    }

#endif // _EXAMINATION_HUAWEI_0320_02_H_