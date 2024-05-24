/*
2024.3.20-HW-第三题-循环依赖
题目描述
给定一组元素，及其依赖关系，一个元素可以依赖于多个元素(不包括自己，被依赖元素不会重复)一个元素也可被多个元素依赖。假定总是存在唯一的循环依赖，请输出该循环依赖。

输入描述
第一行一个正整数
𝑁
N，表示依赖关系的个数。

接下来每一行表示一个依赖关系，是由空格分割的多个正整数，第一个数
𝑛
n表示后面有
𝑛
n个元素，第二个数为元素编号
𝑎
a，后面多个数为
𝑎
a依赖的元素编号，任意元素
𝑖
i满足
0
<
𝑡
<
10000
0<t<10000

输出描述
一串数字，代表这个循环依赖，从最小元素编号开始，按照依赖关系依次输出，以最小元素结束。

样例
输入

3
3 1 2 5
3 2 3 4
2 3 1
输出

1 2 3 1
说明

元素1依赖于2，5
元素2依赖于3，4
元素3依赖于1
*/

#ifndef _EXAMINATION_HUAWEI_0320_03_H_
#define _EXAMINATION_HUAWEI_0320_03_H_

#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool dfs(int curr, vector<int> &path, unordered_set<int> &visited, unordered_map<int, vector<int>> &graph)
{

    if (visited.count(curr))
    {
        return true;
    }

    path.push_back(curr);

    visited.insert(curr);

    if (!graph.count(curr))
    {
        return false;
    }

    bool flag = false;
    for (auto x : graph[curr])
    {
        flag = flag || dfs(x, path, visited, graph);
    }

    return flag;
}

// 3
// 3 1 2 5
// 3 2 3 4
// 2 3 1
void test_0320_03()
{
    int N = 3;
    vector<vector<int>> data = {{3, 1, 2, 5}, {3, 2, 3, 4}, {2, 3, 1}};
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < N; ++i)
    {
        int n = data[i][0];
        int a = data[i][1];
        int b;
        for (int j = 0; j < n - 1; ++j)
        {
            b = data[i][j + 2];
            graph[a].push_back(b);
        }
    }

    vector<int> path;
    for (auto x : graph)
    {
        path.clear();
        unordered_set<int> visited;
        // cout << x.first << ": ";
        // for(auto y: graph[x.first]){
        //     cout << y << " ";
        // }
        // cout << endl;
        if (dfs(x.first, path, visited, graph))
        {
            auto x = min_element(path.begin(), path.end());
            for (auto iter = x; iter != path.end(); ++iter)
            {
                cout << *iter << " ";
            }
            for (auto iter = path.begin(); iter != x; ++iter)
            {
                cout << *iter << " ";
            }
            cout << *x;
            break;
        }
    }

    return 0;
}

#endif // !_EXAMINATION_HUAWEI_0320_03_H_