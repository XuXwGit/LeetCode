/*
1334. 阈值距离内邻居最少的城市
有 n 个城市，按从 0 到 n-1 编号。给你一个边数组 edges，其中 edges[i] = [fromi, toi, weighti] 代表 fromi 和 toi 两个城市之间的双向加权边，距离阈值是一个整数 distanceThreshold。
返回能通过某些路径到达其他城市数目最少、且路径距离 最大 为 distanceThreshold 的城市。如果有多个这样的城市，则返回编号最大的城市。
注意，连接城市 i 和 j 的路径的距离等于沿该路径的所有边的权重之和。
*/

#ifndef _GRAPH_FLOYD_LEETCODE1334_H_
#define _GRAPH_FLOYD_LEETCODE1334_H_

#include "include_std_c++.h"

class Solution1334 {
    void folyd(vector<vector<int>>& distance){
        for(int k = 0; k<distance.size(); ++k){
            for(int i = 0; i<distance.size(); ++i){
                if(i == k){
                    continue;
                }
                for(int j = 0; j<distance.size(); ++j){
                    if(j == k || j == i){
                        continue;
                    }

                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX/2));

        for(auto edge: edges){
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }

        folyd(distance);

        int ans = 0;
        int min_num = INT_MAX;
        for(int i = 0; i<n; ++i){
            int count = 0;
            for(int j = 0; j<n; ++j){
                count += distance[i][j] <= distanceThreshold;
            }
            min_num = min(min_num, count);
            ans = min_num < count? ans : i;
        }

        return ans;
    }
};

void test1334(){
    // n = 4
    // [[0,1,3],[1,2,1],[1,3,4],[2,3,1]]
    // distanceThreshold = 4
    // Output: 3
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    Solution1334 s;
    cout<<s.findTheCity(4, edges, 4)<<endl;

    // n = 5
    // [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]]
    // distanceThreshold = 2
    // Output: 0
    edges = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    cout<<s.findTheCity(5, edges, 2)<<endl;
}

#endif // !_GRAPH_FLOYD_LEETCODE1334_H_