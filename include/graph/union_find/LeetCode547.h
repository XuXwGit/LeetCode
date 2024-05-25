/*
547. 省份数量
已解答
中等
相关标签
相关企业
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。



示例 1：


输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
输出：2
示例 2：


输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
输出：3


*/

#ifndef _LEETCODE_GRAPH_UNION_FIND_547_H_
#define _LEETCODE_GRAPH_UNION_FIND_547_H_

class Solution547
{
private:
    vector<int> parents;
    int find(int x)
    {
        if (parents[x] != x)
        {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }
    void merge(int x, int y)
    {
        if (find(x) != find(y))
        {
            parents[find(x)] = find(y);
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        parents = vector<int>(n);
        for (int i = 0; i < n; ++i)
        {
            parents[i] = i;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (isConnected[i][j])
                {
                    merge(i, j);
                }
            }
        }

        set<int> cls;
        for (int i = 0; i < n; ++i)
        {
            cls.insert(find(i));
        }

        return cls.size();
    }
};

void test547()
{
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    Solution547 solution547;
    cout << solution547.findCircleNum(isConnected) << endl;
    isConnected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    cout << solution547.findCircleNum(isConnected) << endl;
}

#endif // !_LEETCODE_GRAPH_UNION_FIND_547_H_