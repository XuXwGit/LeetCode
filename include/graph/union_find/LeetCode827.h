/*
827. 最大人工岛
困难
相关标签
相关企业
给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。

返回执行此操作后，grid 中最大的岛屿面积是多少？

岛屿 由一组上、下、左、右四个方向相连的 1 形成。



示例 1:

输入: grid = [[1, 0], [0, 1]]
输出: 3
解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
示例 2:

输入: grid = [[1, 1], [1, 0]]
输出: 4
解释: 将一格0变成1，岛屿的面积扩大为 4。
示例 3:

输入: grid = [[1, 1], [1, 1]]
输出: 4
解释: 没有0可以让我们变成1，面积依然为 4。

*/

#ifndef __LEETCODE_GRAPH_UNION_FIND_LEETCODE_827_H__
#define __LEETCODE_GRAPH_UNION_FIND_LEETCODE_827_H__

class Solution827
{
private:
    vector<int> parent;
    vector<int> counts;
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y)
    {
        int p_x = find(x);
        int p_y = find(y);
        if (p_x != p_y)
        {
            parent[p_y] = p_x;
            counts[p_x] += counts[p_y];
        }
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        parent = vector<int>(n * n);
        counts = vector<int>(n * n, 1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                parent[i * n + j] = i * n + j;
            }
        }

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    for (auto direc : directions)
                    {
                        int ii = i + direc[0];
                        int jj = j + direc[1];
                        if (ii < n && jj < n && ii >= 0 && jj >= 0 &&
                            grid[ii][jj] == 1)
                        {
                            merge(i * n + j, ii * n + jj);
                        }
                    }
                }
            }
        }

        int res = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    res = max(res, counts[find(i * n + j)]);
                    continue;
                }
                set<int> blocks;
                int temps = 0;
                for (auto d1 : directions)
                {
                    int ii1 = i + d1[0];
                    int jj1 = j + d1[1];
                    if (ii1 >= n || ii1 < 0 || jj1 >= n || jj1 < 0 ||
                        grid[ii1][jj1] == 0)
                    {
                        continue;
                    }
                    if (blocks.count(find(ii1 * n + jj1)))
                    {
                        continue;
                    }
                    else
                    {
                        blocks.insert(find(ii1 * n + jj1));
                        temps += counts[(find(ii1 * n + jj1))];
                    }
                }
                res = max(res, 1 + temps);
            }
        }
        return res;
    }
};

void test827()
{
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    Solution827 solution;
    cout << solution.largestIsland(grid) << endl;
}

#endif // __LEETCODE_GRAPH_UNION_FIND_LEETCODE_827_H__