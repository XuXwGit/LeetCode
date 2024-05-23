/*
2024.4.17-HW-第二题-云上服务
题目描述

将云服务看做一棵树，每个云服务在发布前尚未解决的问题称为云服务的遗留问题（云服务的遗留问题包含以该云服务为根节点的树上所有节点的问题），DI值（遗留问题缺陷密度）可以作为评估云服务发布的指标，当云服务DI值小于等于阈值时才准许云服务发布，否则视为风险云服务，需要问题整改完成后重新进行发布评估。现有一批云服务树，已给出云服务树各节点的问题数量，请通过计算输出风险云服务的个数。

计算公式：DI值≤5×严重问题数＋2×一般问题数，其中每个节点的不同级别问题数量需要将该节点及该节点为根节点的所有子节点的相应级别问题数量求和。

输入描述
第一行输入𝑀和𝑁(𝑀≤100000，𝑁≤1000)，使用空格分隔，M表示代表云服务阈值，N表示接下来有N行问题统计数据；接下来输入一个𝑁∗4的矩阵表，行内使用空格分隔，第一列𝐴𝑖 为服务节点，第二列𝐵𝑖 为𝐴𝑖 的父节点，如果𝐴𝑖 为云服务则无父节点，此时Bi用∗号表示(𝐴𝑖和𝐵𝑖 取值为字符串，1≤字符串长度≤5，均由小写英文字母或∗号组成)，第三列𝐶𝑖 为问题级别（𝐶𝑖 取值为{0,1}，0表示严重问题，1表示一般问题），第四列𝐷𝑖
​
 为该节点该级别的问题数量(Di≤1000)。

说明：输入保证只出现树的关系，不会出现连通图的情况。

输出描述
输出一个整数，表示风险云服务个数。
*/

#ifndef _EXAMINATION_0417_HUAWEI_02_DFS_H_
#define _EXAMINATION_0417_HUAWEI_02_DFS_H_

#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

struct treenode
{
    string id;
    int num_0;
    int num_1;
    int score;
    set<treenode *> nexts;

    void print()
    {
        cout << id << " : " << score << " ";
        for (auto x : nexts)
        {
            cout << x->id << " ";
        }
        cout << endl;
    }

    treenode(string id) : id(id), num_0(0), num_1(0), score(0) {}
    treenode(string id, int num0, int num1) : id(id), num_0(num0), num_1(num1), score(5 * num0 + 2 * num1) {}
};

unordered_map<string, treenode *> maps;
int counts = 0;

int dfs(treenode *root, int k)
{
    root->score = 5 * root->num_0 + 2 * root->num_1;
    for (auto x : root->nexts)
    {
        root->score += dfs(x, k);
    }

    return root->score;
}

int main()
{

    int m, n;
    cin >> m >> n;

    treenode *root = new treenode("*");
    maps["*"] = root;
    string A;
    string B;
    int C;
    int D;
    for (int i = 0; i < n; ++i)
    {
        cin >> A >> B >> C >> D;
        if (!maps.count(A))
        {
            treenode *node = new treenode(A);
            maps[A] = node;
        }
        if (C == 0)
        {
            maps[A]->num_0 = D;
        }
        else if (C == 1)
        {
            maps[A]->num_1 = D;
        }

        if (!maps.count(B))
        {
            treenode *node = new treenode(B);
            maps[B] = node;
        }
        maps[B]->nexts.insert(maps[A]);
    }

    int counts = 0;
    for (auto x : maps["*"]->nexts)
    {
        if (dfs(x, m) > m)
        {
            counts++;
        }
    }

    cout << counts << endl;

    return 0;
}

#endif // _EXAMINATION_0417_HUAWEI_02_DFS_H_