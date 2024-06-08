/*
407. 接雨水 II
已解答
困难
相关标签
相关企业
给你一个 m x n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。



示例 1:



输入: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
输出: 4
解释: 下雨后，雨水将会被上图蓝色的方块中。总的接雨水量为1+2+1=4。
示例 2:



输入: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
输出: 10


提示:

m == heightMap.length
n == heightMap[i].length
1 <= m, n <= 200
0 <= heightMap[i][j] <= 2 * 10^4
*/

#ifndef _LEETCODE_GRAPH_DIJKSTRA_LEETCODE407_H_
#define _LEETCODE_GRAPH_DIJKSTRA_LEETCODE407_H_

class Solution407
{
private:
    void dijkstra(vector<vector<bool>> &visited,
                  const vector<vector<int>> &heightMap)
    {
        int m = heightMap.size();
        int n = heightMap[0].size();
        // (height, row, col)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        for (int j = 0; j < n; ++j)
        {
            visited[0][j] = true;
            pq.emplace(heightMap[0][j], 0, j);
            visited[m - 1][j] = true;
            pq.emplace(heightMap[m - 1][j], m - 1, j);
        }
        for (int i = 1; i < m - 1; ++i)
        {
            visited[i][0] = true;
            pq.emplace(heightMap[i][0], i, 0);
            visited[i][n - 1] = true;
            pq.emplace(heightMap[i][n - 1], i, n - 1);
        }
        while (!pq.empty())
        {
            auto [height, x, y] = pq.top();
            pq.pop();

            vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for (auto dxy : directions)
            {
                int dx = x + dxy[0];
                int dy = y + dxy[1];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n)
                {
                    if (visited[dx][dy])
                    {
                        continue;
                    }
                    if (heightMap[dx][dy] < height)
                    {
                        res += height - heightMap[dx][dy];
                    }
                    visited[dx][dy] = true;
                    pq.emplace(max(height, heightMap[dx][dy]), dx, dy);
                }
            }
        }
    }
    int res = 0;

public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int m = heightMap.size();
        int n = heightMap[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        dijkstra(visited, heightMap);

        return res;
    }
};

void test407()
{
    cout << " ==== test407 ==== " << endl;
    Solution407 solution;
    vector<vector<int>> heightMap = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    cout << solution.trapRainWater(heightMap) << endl;
    heightMap = {{3, 3, 3, 3, 3}, {3, 2, 2, 2, 3}, {3, 2, 1, 2, 3}, {3, 2, 2, 2, 3}, {3, 3, 3, 3, 3}};
    cout << solution.trapRainWater(heightMap) << endl;
}

#endif