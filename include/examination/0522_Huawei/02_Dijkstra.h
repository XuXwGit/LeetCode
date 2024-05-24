/*
2. 矿车运输成本
露天矿采矿作业的特点是规模大，矿石和废料的移动量达到百万吨，运输成本开销较大，需要寻求一种最优的运输路径节省成本。

已知矿场可以划分成N*M的网格图，每个网格存在地形的差异，因此通过不同网格时，成本开销存在差异。

网格有以下5种类型：

1、标志为'S’的网格为运输起点；
2、标志为'E”的网格时运输终点；
3、标志为'B’的网格为阻塞点，不允许通行；
4、标志为'C'的网格为检查点，矿车在运输路径中，至少需要进入一次检查点。
5、标志为‘数字”的网格，其数字表示经过该网格的成本开销。
运输矿车只能上下左右4个方向运行，不允许斜对角进入其他网格。必要时可重复进入网格。
请根据输入的网格图，寻求一条从S网格到E网格，并且至少经过一次检查点的最低成本运输路径，并输出其成本开销。
解答要求

时间限制: C/C++ 1000ms,其他语言: 2000ms内存限制: C/C++ 256MB, 其他语言: 512MB

输入

第一行：网格图的行数N[3,200]和网格图的列数M[3,200]，使用空格隔开。

第二行至第N+1行：网格图每一行的元素，可以为'S’，E’，'B'，‘C'或者数字[0,100]，并且有且仅有一个'S’和一个'E’，同时存在一个或者多个‘C'，并依次使用空格隔开。

输出：

第一行：输出运输最低成本开销。如果不存在可达通路，请输出-1

示例 1：

输入：

3 3
S 4 5
7 B 3
C 9 E
输出：

16
*/

#ifndef _EXAMINATION_0522_HUAWEI_02_MINCOST_H_
#define _EXAMINATION_0522_HUAWEI_02_MINCOST_H_

class Solution0522_HW_02
{
private:
    unordered_map<int, vector<pair<int, int>>> graph;
    void dijkstra(int origin, vector<int> &distance)
    {
    }

public:
    int minCost(vector<vector<string>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        unordered_set<int> checkPoints;
        unordered_map<int, int> costs;
        int start = 0;
        int end = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == "B")
                {
                    continue;
                }

                if (grid[i][j] == "C")
                {
                    checkPoints.emplace(i, j);
                    costs[i * m + j] = 0;
                }
                else if (grid[i][j] == "S")
                {
                    start = i * m + j;
                    costs[i * m + j] = 0;
                }
                else if (grid[i][j] == "E")
                {
                    end = i * m + j;
                    costs[i * m + j] = 0;
                }
                else
                {
                    costs[i * m + j] = stoi(grid[i][j]);
                }
            }
        }

        // build graph
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == "B")
                {
                    continue;
                }

                for (auto &dir : directions)
                {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != "B")
                    {
                        graph[i * m + j].emplace_back(x * m + y, costs[x * m + y]);
                    }
                }
            }
        }
    }
};

void test_HW_0522_02()
{
    vector<vector<char>> grid = {
        {'S', '4', '5'},
        {'7', 'B', '3'},
        {'C', '9', 'E'}};
    Solution0522_HW_02 solution;
    int res = solution.minCost(grid);
    cout << res << endl;
}

#endif // !_EXAMINATION_0522_HUAWEI_02_MINCOST_H_