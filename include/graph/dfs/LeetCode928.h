/*
928. 尽量减少恶意软件的传播 II
给定一个由 n 个节点组成的网络，用 n x n 个邻接矩阵 graph 表示。在节点网络中，只有当 graph[i][j] = 1 时，节点 i 能够直接连接到另一个节点 j。
一些节点 initial 最初被恶意软件感染。只要两个节点直接连接，且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。
假设 M(initial) 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。
我们可以从 initial 中删除一个节点，并完全移除该节点以及从该节点到任何其他节点的任何连接。
请返回移除后能够使 M(initial) 最小化的节点。如果有多个节点满足条件，返回索引 最小的节点 。
*/

#ifndef _LEETCODE_928_H_   
#define _LEETCODE_928_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

class Solution928 {
private:
    vector<vector<int>> graph;
    vector<bool> isvisited;
    unordered_set<int> initial_sets;
    void dfs(int i, int& size, int& num_initial){
        if(isvisited[i]){
            return;
        }

        if(initial_sets.count(i)){
            // if num_initial == -1, means the first time to visit initial node
            // if num_initial == i, means the second time to visit the same initial node
            // else means the second time to visit another initial node
            num_initial = (num_initial == -1 || num_initial == i)? i : -2;
            return;
        }

        size ++;
        isvisited[i] = true;

        for(int j = 0; j<graph.size(); ++j){
            if(!isvisited[j] && graph[i][j]){
                dfs(j, size, num_initial);
            }
        }
    }
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        this->graph = graph;
        this->isvisited = vector<bool>(graph.size(), false);
        this->initial_sets = unordered_set<int>(initial.begin(), initial.end());
        
        // Note : here map should use multimap: because there may includes multi connected subgraph with the same size
        map<int, int> sizes;
        for(int i = 0; i<graph.size(); ++i){
            if(!initial_sets.count(i) && !isvisited[i]){
                int size = 0;
                int num_initial = -1;
                dfs(i, size, num_initial);
                if(num_initial >= 0){
                    sizes[num_initial] += size;
                }
            }
        }

        int ans = 0;
        int max_size = 0;
        for(auto x: sizes){
            if(max_size < x.second || max_size == x.second && ans > x.first){
                max_size = x.second;
                ans = x.first;
            }
        }

        return sizes.empty() ? *min_element(initial.begin(), initial.end())  : ans;
    }
};



void test928(){
    // [[1,0,0,1],[0,1,1,0],[0,1,1,0],[1,0,0,1]]
    // [3,1]
    vector<vector<int>> graph = {{1,0,0,1},
                                  {0,1,1,0},
                                  {0,1,1,0},
                                  {1,0,0,1}};
    vector<int> initial = {3,1};
    Solution928 solution;
    cout << solution.minMalwareSpread(graph, initial) << endl;

    // [[1,0,0,0,0,0,0,0,1],[0,1,0,1,0,0,0,0,0],[0,0,1,1,0,1,0,0,0],[0,1,1,1,1,0,1,0,0],[0,0,0,1,1,1,0,0,0],[0,0,1,0,1,1,0,0,0],[0,0,0,1,0,0,1,1,0],[0,0,0,0,0,0,1,1,1],[1,0,0,0,0,0,0,1,1]]
    // [3, 7]
    graph = {{1,0,0,0,0,0,0,0,1},
             {0,1,0,1,0,0,0,0,0},
             {0,0,1,1,0,1,0,0,0},
             {0,1,1,1,1,0,1,0,0},
             {0,0,0,1,1,1,0,0,0},
             {0,0,1,0,1,1,0,0,0},
             {0,0,0,1,0,0,1,1,0},
             {0,0,0,0,0,0,1,1,1},
             {1,0,0,0,0,0,0,1,1}};
    initial = {3, 7};
    cout << solution.minMalwareSpread(graph, initial) << endl;
}

#endif // _LEETCODE_928_H_