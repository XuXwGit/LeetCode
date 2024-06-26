/*
1738. 找出第 K 大的异或坐标值
已解答
中等
相关标签
相关企业
提示
给你一个二维矩阵 matrix 和一个整数 k ，矩阵大小为 m x n 由非负整数组成。

矩阵中坐标 (a, b) 的 值 可由对所有满足 0 <= i <= a < m 且 0 <= j <= b < n 的元素 matrix[i][j]（下标从 0 开始计数）执行异或运算得到。

请你找出 matrix 的所有坐标中第 k 大的值（k 的值从 1 开始计数）。



示例 1：

输入：matrix = [[5,2],[1,6]], k = 1
输出：7
解释：坐标 (0,1) 的值是 5 XOR 2 = 7 ，为最大的值。
示例 2：

输入：matrix = [[5,2],[1,6]], k = 2
输出：5
解释：坐标 (0,0) 的值是 5 = 5 ，为第 2 大的值。
示例 3：

输入：matrix = [[5,2],[1,6]], k = 3
输出：4
解释：坐标 (1,0) 的值是 5 XOR 1 = 4 ，为第 3 大的值。
示例 4：

输入：matrix = [[5,2],[1,6]], k = 4
输出：0
解释：坐标 (1,1) 的值是 5 XOR 2 XOR 1 XOR 6 = 0 ，为第 4 大的值。


提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
0 <= matrix[i][j] <= 106
1 <= k <= m * n
*/

#ifndef _LEETCODE_MATH_LEETCODE1738_H_
#define _LEETCODE_MATH_LEETCODE1738_H_

class Solution1738
{
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> xors(m, vector<int>(n, 0));
        vector<int> res;
        for (int i = 0; i < m; ++i)
        {
            int temp = 0;
            for (int j = 0; j < n; ++j)
            {
                temp ^= matrix[i][j];
                xors[i][j] = temp;
                if (i > 0)
                {
                    xors[i][j] ^= xors[i - 1][j];
                }
                res.push_back(xors[i][j]);
            }
        }

        sort(res.begin(), res.end(), greater<int>());

        return res[k - 1];
    }
};

void test1738()
{
    vector<vector<int>> matrix = {{5, 2}, {1, 6}};
    int k = 1;
    Solution1738 solution1738;
    cout << solution1738.kthLargestValue(matrix, k) << endl;

    k = 2;
    cout << solution1738.kthLargestValue(matrix, k) << endl;

    // [[8,10,5,8,5,7,6,0,1,4,10,6,4,3,6,8,7,9,4,2]]
    // 2
    matrix = {{8, 10, 5, 8, 5, 7, 6, 0, 1, 4, 10, 6, 4, 3, 6, 8, 7, 9, 4, 2}};
    k = 2;
    cout << solution1738.kthLargestValue(matrix, k) << endl;
}

#endif // !_LEETCODE_MATH_LEETCODE1738_H_