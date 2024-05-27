/*
2101. 引爆最多的炸弹
已解答
中等
相关标签
相关企业
提示
给你一个炸弹列表。一个炸弹的 爆炸范围 定义为以炸弹为圆心的一个圆。

炸弹用一个下标从 0 开始的二维整数数组 bombs 表示，其中 bombs[i] = [xi, yi, ri] 。xi 和 yi 表示第 i 个炸弹的 X 和 Y 坐标，ri 表示爆炸范围的 半径 。

你需要选择引爆 一个 炸弹。当这个炸弹被引爆时，所有 在它爆炸范围内的炸弹都会被引爆，这些炸弹会进一步将它们爆炸范围内的其他炸弹引爆。

给你数组 bombs ，请你返回在引爆 一个 炸弹的前提下，最多 能引爆的炸弹数目。



示例 1：



输入：bombs = [[2,1,3],[6,1,4]]
输出：2
解释：
上图展示了 2 个炸弹的位置和爆炸范围。
如果我们引爆左边的炸弹，右边的炸弹不会被影响。
但如果我们引爆右边的炸弹，两个炸弹都会爆炸。
所以最多能引爆的炸弹数目是 max(1, 2) = 2 。
示例 2：



输入：bombs = [[1,1,5],[10,10,5]]
输出：1
解释：
引爆任意一个炸弹都不会引爆另一个炸弹。所以最多能引爆的炸弹数目为 1 。
示例 3：



输入：bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
输出：5
解释：
最佳引爆炸弹为炸弹 0 ，因为：
- 炸弹 0 引爆炸弹 1 和 2 。红色圆表示炸弹 0 的爆炸范围。
- 炸弹 2 引爆炸弹 3 。蓝色圆表示炸弹 2 的爆炸范围。
- 炸弹 3 引爆炸弹 4 。绿色圆表示炸弹 3 的爆炸范围。
所以总共有 5 个炸弹被引爆。
*/

#ifndef _GRAPH_BFS_LEETCODE2101_H_
#define _GRAPH_BFS_LEETCODE2101_H_

class Solution2101
{
private:
    int dfs(int i, vector<bool> &visited, unordered_map<int, vector<int>> &graph)
    {
        if (visited[i])
        {
            return 0;
        }

        visited[i] = true;

        int count = 1;
        for (int j : graph[i])
        {
            count += dfs(j, visited, graph);
        }

        return count;
    }

    int bfs(int i, vector<bool> &visited, unordered_map<int, vector<int>> &graph)
    {
        int count = 0;
        queue<int> pq;
        pq.push(i);
        count++;
        visited[i] = true;
        while (!pq.empty())
        {
            for (int j : graph[pq.front()])
            {
                if (!visited[j])
                {
                    pq.push(j);
                    count++;
                    visited[j] = true;
                }
            }
            pq.pop();
        }

        return count;
    }

public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        unordered_map<int, vector<int>> graph;

        int n = bombs.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                long long distance = (long long)(bombs[i][0] - bombs[j][0]) * (bombs[i][0] - bombs[j][0]) + (long long)(bombs[i][1] - bombs[j][1]) * (bombs[i][1] - bombs[j][1]);
                if (distance <= (long long)bombs[i][2] * bombs[i][2])
                {
                    graph[i].push_back(j);
                }
                if (distance <= (long long)bombs[j][2] * bombs[j][2])
                {
                    graph[j].push_back(i);
                }
            }
        }

        int res = 1;
        for (int i = 0; i < n; ++i)
        {
            vector<bool> visited(n, false);
            // res = max(res, dfs(i, visited, graph));
            res = max(res, bfs(i, visited, graph));
        }

        return res;
    }
};

void test2101()
{
    Solution2101 solution2101;
    vector<vector<int>> bombs = {{2, 1, 3}, {6, 1, 4}};
    cout << solution2101.maximumDetonation(bombs) << endl;
    bombs = {{1, 1, 5}, {10, 10, 5}};
    cout << solution2101.maximumDetonation(bombs) << endl;
    bombs = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};
    cout << solution2101.maximumDetonation(bombs) << endl;
}

#endif // !_GRAPH_BFS_LEETCODE2101_H_