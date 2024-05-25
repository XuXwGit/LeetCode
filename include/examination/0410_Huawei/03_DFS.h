/*
2024.4.10-HW-第三题-公网下线方案
题目描述
公有云的某个region内，
𝑁
N个网络节点组网情况可以使用一个n×n的矩阵matrix表示，在这个组网图中，matrix[i][j]=p时，表示用户在编号为i的节点访问编号为j的节点时，必须在i节点上具有≥p的权限等级(p=0 时表示无法通过
i节点访问j节点)，如果用户成功访问了j节点，那么它在j节点上的权限等级调整为p。 exposed为一个整数数组，表示暴露在公网上的网络节点的编号列表。某天扫描发现这批暴露在公网的节点存在被外部恶意攻击风险，且该攻击会影响到可访问的其他节点，并可以持续传递进行攻击。被恶意攻击的节点从公网访问时，攻击者获得了ROOT权限(权限等级为10，即最大值)。 塔子哥是一名网络安全工程师，为了在有限的时间内尽可能的减少故障带来的损失，需要立即将某个节点从公网"下线"。 假设攻击结束时，被攻击过的节点数量为
R，请帮塔子哥计算出将哪个节点下线能使R尽可能小，如果答案有多个节点，返回索引最小的那个节点。请注意:从公网“下线”的节点，不会受到来自公网的攻击，但仍然可能被“可访问"的其他节点传递攻击。

输入描述
输入的第一行是网络节点数量N 后续的N行，每行N个数字v，以空格分割，形成一个𝑁×𝑁的矩阵，表示网络节点组网的矩阵。 最后一行，输入exposed数组，表示暴露在公网上的网络节点的编号列表数组元素不会重复。
2≤N≤24

0≤v≤10

0≤exposed[i]≤N−1

输出描述
输出在 exposed 数组中，计划“下线"的那个节点的编号。

样例1
输入

4
1 0 0 0
0 1 2 0
0 1 1 4
0 0 3 1
1 3
输出

3
说明

1,3是公网暴露的节点
1,2,3三个节点是连通的，但相互访问需要考虑权限等级限制，例如从1节点登录，访问到2节点后，权限等级不足以访问3号节点
如果将1号节点从公网下线，那3号节点可以先访问2号在访问1号，
*/

#ifdef _EXAMINATION_0410_HUAWEI_03_DFS_H_
#define _EXAMINATION_0410_HUAWEI_03_DFS_H_

#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;

void dfs(int x, int p, set<int> &visited, vector<vector<int>> &distance)
{
    if (visited.count(x))
    {
        return;
    }

    visited.insert(x);

    int N = distance.size();
    for (int i = 0; i < N; ++i)
    {
        if (distance[x][i] != 0 && distance[x][i] <= p)
        {
            dfs(i, distance[x][i], visited, distance);
        }
    }
}

int solution(int N, vector<vector<int>> &distance, vector<int> &exposed)
{
    sort(exposed.begin(), exposed.end());

    unordered_map<int, set<int>> infues;
    for (int x : exposed)
    {
        set<int> visited;
        dfs(x, 10, visited, distance);
        infues[x] = visited;
    }

    int result_node;
    int R = INT_MAX;
    for (int x : exposed)
    {
        set<int> temps;
        for (int y : exposed)
        {
            if (y != x)
            {
                for (auto k : infues[y])
                {
                    temps.insert(k);
                }
            }
        }
        if (R > (int)temps.size())
        {
            R = temps.size();
            result_node = x;
        }
    }

    return result_node;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> distance(N, vector<int>(N, INT_MAX));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> distance[i][j];
        }
    }

    vector<int> exposed;
    int num;
    while (cin >> num)
    {
        exposed.push_back(num);
    }

    cout << solution(N, distance, exposed);

    return 0;
}

#endif // _EXAMINATION_0410_HUAWEI_03_DFS_H_