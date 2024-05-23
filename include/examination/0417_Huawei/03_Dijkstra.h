

#ifndef _EXAMINATION_0417_HUAWEI_03_DIJKSTRA_H_
#define _EXAMINATION_0417_HUAWEI_03_DIJKSTRA_H_

#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> delay;
    vector<int> capacity;

public:
    Solution(vector<vector<int>> &delay, vector<int> &capacity)
        : delay(delay), capacity(capacity) {}
    vector<int> getpath(int k, int need)
    {
        int n = capacity.size();

        // why there can't use : distance = delay[k];????
        vector<int> distance(n, INT_MAX / 2);
        distance[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, k);
        pq.emplace(0, k);

        while (!pq.empty())
        {
            int x = pq.top().first;
            int idx = pq.top().second;

            pq.pop();
            if (x > distance[idx])
            {
                continue;
            }

            for (int i = 0; i < n; ++i)
            {
                if (distance[i] > distance[idx] + delay[idx][i])
                {
                    distance[i] = distance[idx] + delay[idx][i];
                    pq.emplace(distance[i], i);
                }
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dis;
        for (int i = 0; i < n; ++i)
        {
            dis.emplace(distance[i], i);
        }

        vector<int> res;
        while (need > 0 && !dis.empty())
        {
            if (dis.top().second != k)
            {
                need -= capacity[dis.top().second];
                res.push_back(dis.top().second);
            }
            dis.pop();
        }

        return res;
    }
};

void test_0417_03()
{

    // 4
    // -1 5 - 1 8
    // 5 - 1 1 3
    // - 1 1 - 1 4
    // 8 3 4 - 1
    // 10 20 15 25
    // 2
    // 12

    int n = 4;

    vector<vector<int>> delay = {
        {-1, 5, -1, 8},
        {5, -1, 1, 3},
        {-1, 1, -1, 4},
        {8, 3, 4, -1}};

    vector<int> capacity = {10, 20, 15, 25};

    int k = 2;

    int need = 12;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (delay[i][j] == -1)
            {
                delay[i][j] = INT_MAX / 2;
            }
        }
    }

    Solution sol(delay, capacity);
    vector<int> path = sol.getpath(k, need);
    for (auto x : path)
    {
        cout << x << " ";
    }
}

#endif // _EXAMINATION_0417_HUAWEI_03_DIJKSTRA_H_