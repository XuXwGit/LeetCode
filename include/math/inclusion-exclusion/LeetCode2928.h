/*
2928. 给小朋友们分糖果 I
简单
相关标签
相关企业
提示
给你两个正整数 n 和 limit 。

请你将 n 颗糖果分给 3 位小朋友，确保没有任何小朋友得到超过 limit 颗糖果，请你返回满足此条件下的 总方案数 。



示例 1：

输入：n = 5, limit = 2
输出：3
解释：总共有 3 种方法分配 5 颗糖果，且每位小朋友的糖果数不超过 2 ：(1, 2, 2) ，(2, 1, 2) 和 (2, 2, 1) 。
示例 2：

输入：n = 3, limit = 3
输出：10
解释：总共有 10 种方法分配 3 颗糖果，且每位小朋友的糖果数不超过 3 ：(0, 0, 3) ，(0, 1, 2) ，(0, 2, 1) ，(0, 3, 0) ，(1, 0, 2) ，(1, 1, 1) ，(1, 2, 0) ，(2, 0, 1) ，(2, 1, 0) 和 (3, 0, 0) 。


提示：

1 <= n <= 50
1 <= limit <= 50
*/

#ifndef _LEETCODE_MATH_INCLUSION_EXCLUSION_LEETCODE2928_H_
#define _LEETCODE_MATH_INCLUSION_EXCLUSION_LEETCODE2928_H_

class Solution2928
{
private:
    int combineCount(int n, int m)
    {
        if (n < m)
        {
            return 0;
        }
        int res1 = 1, res2 = 1;
        int n2 = 1;
        while (m--)
        {
            res1 *= n--;
            res2 *= n2++;
        }
        return res1 / res2;
    }

public:
    int distributeCandies(int n, int limit)
    {
        if (limit * 3 < n)
        {
            return 0;
        }

        return combineCount(n + 2, 2) - 3 * combineCount(n + 2 - (limit + 1), 2) + 3 * combineCount(n + 2 - 2 * (limit + 1), 2) - combineCount(n + 2 - 3 * (limit + 1), 2);
    }
};

void test2928()
{
    Solution2928 solution2928;
    int n = 5, limit = 2;
    int res = solution2928.distributeCandies(n, limit);
    std::cout << "res: " << res << std::endl;
}

#endif