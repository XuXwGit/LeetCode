/*
2976. 转换字符串的最小成本 I
给你两个下标从 0 开始的字符串 source 和 target ，它们的长度均为 n 并且由 小写 英文字母组成。
另给你两个下标从 0 开始的字符数组 original 和 changed ，以及一个整数数组 cost ，其中 cost[i] 代表将字符 original[i] 更改为字符 changed[i] 的成本。
你从字符串 source 开始。在一次操作中，如果 存在 任意 下标 j 满足 cost[j] == z  、original[j] == x 以及 changed[j] == y 。你就可以选择字符串中的一个字符 x 并以 z 的成本将其更改为字符 y 。
返回将字符串 source 转换为字符串 target 所需的 最小 成本。如果不可能完成转换，则返回 -1 。

注意，可能存在下标 i 、j 使得 original[j] == original[i] 且 changed[j] == changed[i] 。
*/

#ifndef _GRAPH_FLOYD_LEETCODE2976_H_
#define _GRAPH_FLOYD_LEETCODE2976_H_


#include "include_std_c++.h"


class Solution2976 {
private:
    void floyd(vector<vector<int>> &distance)
    {
        int n = distance.size();
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                if (i == k || distance[i][k] >= INT_MAX / 2)
                {
                    continue;
                }
                for (int j = 0; j < n; ++j)
                {
                    if (j == k || distance[k][j] >= INT_MAX / 2)
                    {
                        continue;
                    }
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }

public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        // build graph
        vector<vector<int>> distance(26, vector<int>(26, INT_MAX / 2));
        for (int i = 0; i < distance.size(); ++i)
        {
            distance[i][i] = 0;
        }
        for (int i = 0; i < original.size(); ++i)
        {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            distance[x][y] = min(distance[x][y], cost[i]);
        }

        floyd(distance);

        long long res = 0ll;
        for (int i = 0; i < source.size(); ++i)
        {
            int change_cost = distance[source[i] - 'a'][target[i] - 'a'];
            if (change_cost >= INT_MAX / 2)
            {
                return -1;
            }
            res += change_cost;
        }

        return res;
    }
};

void test2976(){
    // source = "aaaa", target = "bbbb", original = ['a','c'], changed = ['c','b'], cost = [1,2]
    // Output: 2
    string source = "aaaa";
    string target = "bbbb";
    vector<char> original = {'a','c'};
    vector<char> changed = {'c','b'};
    vector<int> cost = {1,2};
    Solution2976 s;
    cout<<s.minimumCost(source, target, original, changed, cost)<<endl;

    // source = ""abcd"", target = ""acbe"", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
    // Output: 26
    source = "abcd";
    target = "acbe";
    original = {'a','b','c','c','e','d'};
    changed = {'b','c','b','e','b','e'};
    cost = {2,5,5,1,2,20};
    cout<<s.minimumCost(source, target, original, changed, cost)<<endl;

    // source = ""abcd"", target = ""abce"", original = ['a'], changed = ['e'], cost = [1000]
    source = "abcd";
    target = "abce";
    original = {'a'};
    changed = {'e'};
    cost = {1000};
    cout<<s.minimumCost(source, target, original, changed, cost)<<endl;
}

#endif // !_GRAPH_FLOYD_LEETCODE2976_H_