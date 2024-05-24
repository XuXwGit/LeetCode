/*
2024.4.10-HW-第二题-相似度计算
题目描述
塔子哥想要处理一批图片，将相似的图片分类。他首先对图片的特征采样，得到图片之间的相似度，然后按照以下规则判断图片是否可以归为一类: 1)相似度>0表示两张图片相似; 2)如果A和B相似，B和C相似，但A和C不相似。那么认为A和C间接相似，可以把ABC归为一类，但不计算AC的相似度: 3)如果A和所有其他图片都不相似，则A自己归为一类，相似度为0。给定一个大小为
N×N的矩阵
M存储任意两张图片的相似度，M]即为第i个图片和第j个图片的相似度，请按照"从大到小"的顺序返回每个相似类中所有图片的相似度之和。

输入描述
第一行一个数
N(1≤N≤900)，代表矩阵M中有N个图片。下面跟着N行，每行有N列数据，空格分隔(为了显示整齐，空格可能为多个)，代表N个图片之间的相似度。
其中0≤M[i][j]≤100，输入保证M[i][j]=M[j][i]输入的矩阵分隔符为1个或多个连续空格
输出描述
每个相似类的相似度之和。格式为:一行数字，分隔符为1个空格
*/

#ifndef _EXAMINATION_0410_HUAWEI_02_UNIONFINDSET_H_
#define _EXAMINATION_0410_HUAWEI_02_UNIONFINDSET_H_

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class solution_0410_02
{
private:
    int n;
    vector<int> parents;
    int find(int x)
    {
        if (parents[x] != x)
        {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }
    void merge(int x, int y, int w)
    {
        if (find(x) != find(y))
        {
            parents[find(x)] = find(y);
        }
    }

public:
    solution_0410_02(int n, vector<vector<int>> &grid) : n(n)
    {
        parents = vector<int>(n, 0);
        for (int i = 0; i < n; ++i)
        {
            parents[i] = i;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] > 0)
                {
                    merge(i, j, grid[i][j]);
                }
            }
        }

        map<int, int> res;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (find(i) == find(j) && grid[i][j] > 0)
                {
                    res[find(i)] += grid[i][j];
                }
            }
        }

        vector<int> result;
        for (auto x : res)
        {
            result.push_back(x.second);
        }

        sort(result.begin(), result.end(), greater<int>());
        for (auto x : result)
        {
            cout << x << " ";
        }
    }
};

void test_0410_02()
{
    // 5
    // 0 0 50 0 0
    // 0 0 0 25 0
    // 50 0 0 0 15
    // 0 25 0 0 0
    // 0 0 15 0 0
    int n = 5;

    vector<vector<int>> grid = {
        {0, 0, 50, 0, 0},
        {0, 0, 0, 25, 0},
        {50, 0, 0, 0, 15},
        {0, 25, 0, 0, 0},
        {0, 0, 15, 0, 0}};

    solution_0410_02 sol(n, grid);
}

#endif // _EXAMINATION_0410_HUAWEI_02_UNIONFINDSET_H_