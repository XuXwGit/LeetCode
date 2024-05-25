/*
2024.4.24-HW-第三题-塔子哥的微服务群组
题目描述
上期我们聊到，你为了帮助塔子哥维护云服务器而大打出手。如今，云服务器已经平稳运行并给用户们提供了一系列不错的服务，但是塔子哥仍花了很多时间在运维和数据分析上。

更形式的，塔子哥为了调研微服务调用情况，对n个微服务调用数据进行了采集分析,微服务使用数字0至n−1进行编号，给你一个下标从
0开始的数组edges，其中edges[i]表示存在一条从微服务
i到微服务
edges[i]的接口调用。

为了更好的维护，塔子哥将形成
1个环的多个微服务称为微服务群组，一个微服务群组的所有微服务数量为L，能够访问到该微服务群组的微服务数量为V，这个微服务群组的内聚值
H=L−V。

已知提供的数据中有1个或多个微服务群组，请按照内聚值H的结果从大到小的顺序对所有微服务群组(H相等时，取环中最大的数进行比较)排序，输出排在第一的做服务群组，输出时每个微服务群组输出的起始编号为环中最小的数。

输入描述
第一行输入n，表示有n个微服务
第二行为数组edges,其中
edges[i]表示存在一条从微服务
i到微服务
edges[i]的接口调用，数字以空格分隔。

数据范围：
edges.length
2≤n≤10
0≤edges[i]≤n−1

输入保证

edges[i]=i

输出描述
输出排在第一的微服务群组的编号数组，按照环的访问顺序输出，起始编号为环中最小的数，数字以空格分隔。

样例一
输入

4
3 3 0 2
输出

0 3 2
解释

0，3，2组成了微服务群组 (环)a，他的L值为3，对于a来说，只有编号为1的1个微服务可以访问到a，因此a的为1答案输出微服务群组为0 3 2

样例二
输入

12
2 6 10 1 6 0 3 0 5 4 5 8
输出

0 2 10 5
*/

#ifndef _EXAMINATION_0424_HUAWEI_03_DFS_H_
#define _EXAMINATION_0424_HUAWEI_03_DFS_H_

#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

void solution_HW_0424_02(int n, vector<int> &edges)
{
    vector<int> indegree(n, 0);

    for (int i = 0; i < n; ++i)
    {
        indegree[edges[i]]++;
    }

    stack<int> zero_nodes;
    vector<int> visited(n, false);

    for (int i = 0; i < n; ++i)
    {
        if (indegree[i] == 0)
        {
            zero_nodes.push(i);
        }
    }

    unordered_map<int, int> pre_counts;
    while (!zero_nodes.empty())
    {
        int curr = zero_nodes.top();
        zero_nodes.pop();
        visited[curr] = true;

        int next = edges[curr];
        pre_counts[next] += pre_counts[curr] + 1;

        indegree[next]--;

        if (indegree[next] == 0)
        {
            zero_nodes.push(next);
        }
    }

    priority_queue<tuple<int, int, vector<int>>> cycles;
    for (int i = 0; i < n; ++i)
    {
        if (indegree[i] == 0 || visited[i] == true)
        {
            continue;
        }
        else if (indegree[i] == 1)
        {
            vector<int> res;
            int start = i;
            int V = 0;
            int max_p = start;
            while (edges[start] != i)
            {
                res.push_back(start);
                V += pre_counts[start];
                visited[start] = true;
                max_p = max(max_p, start);

                start = edges[start];
            }
            res.push_back(start);
            V += pre_counts[start];
            visited[start] = true;
            max_p = max(max_p, start);
            int L = res.size();
            cycles.emplace(L - V, max_p, res);

            // for(auto x: res){
            //     cout << x << " ";
            // }
            // cout << "\t\t" << L-V << endl;
        }
        else
        {
            cout << "Error: " << i << endl;
        }
    }

    for (auto x : get<2>(cycles.top()))
    {
        cout << x << " ";
    }
}
void test_0424_03()
{

    // 45
    // 17 4 23 13 18 9 16 24 14 11 33 41 42 31 17 31 18 16 26 32 27 27 13 27 13 3 11 31 34 3 3 28 37 8 29 13 32 25 41 1 20 34 14 37 18
    int n = 45;
    // cin >> n;

    // vector<int> edges = vector<int>(n);
    vector<int> edges = {17, 4, 23, 13, 18, 9, 16, 24, 14, 11, 33, 41, 42, 31, 17, 31, 18, 16, 26, 32, 27, 27, 13, 27, 13, 3, 11, 31, 34, 3, 3, 28, 37, 8, 29, 13, 32, 25, 41, 1, 20, 34, 14, 37, 18};
    // for (int i = 0; i < n; ++i)
    // {
    //     cin >> edges[i];
    // }

    solution_HW_0424_02(n, edges);
}

#endif // _EXAMINATION_0424_HUAWEI_03_DFS_H_