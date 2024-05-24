/*
3112. 访问消失节点的最少时间
已解答
中等
相关标签
相关企业
提示
给你一个二维数组 edges 表示一个 n 个点的无向图，其中 edges[i] = [ui, vi, lengthi] 表示节点 ui 和节点 vi 之间有一条需要 lengthi 单位时间通过的无向边。

同时给你一个数组 disappear ，其中 disappear[i] 表示节点 i 从图中消失的时间点，在那一刻及以后，你无法再访问这个节点。

注意，图有可能一开始是不连通的，两个节点之间也可能有多条边。

请你返回数组 answer ，answer[i] 表示从节点 0 到节点 i 需要的 最少 单位时间。如果从节点 0 出发 无法 到达节点 i ，那么 answer[i] 为 -1 。
*/

#ifndef _DIJKSTRA_LEETCODE3112_H_
#define _DIJKSTRA_LEETCODE3112_H_

class Solution3112
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto x : edges)
        {
            graph[x[0]].emplace_back(x[1], x[2]);
            graph[x[1]].emplace_back(x[0], x[2]);
        }

        vector<int> distance(n, INT_MAX / 2);
        distance[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 0);

        while (!pq.empty())
        {
            auto [x, idx] = pq.top();
            pq.pop();

            if (x > distance[idx])
            {
                continue;
            }

            for (auto [y, cost] : graph[idx])
            {
                if (distance[y] > x + cost && x + cost < disappear[y])
                {
                    distance[y] = x + cost;
                    pq.emplace(distance[y], y);
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (distance[i] >= INT_MAX / 2)
            {
                distance[i] = -1;
            }
        }

        return distance;
    }
};

void test3112()
{
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {0, 3, 1}};
    vector<int> disappear = {1, 2};
    Solution3112 s;
    vector<int> res = s.minimumTime(4, edges, disappear);
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;
}

#endif // _DIJKSTRA_LEETCODE3112_H_