/*
1631. 最小体力消耗路径
你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。
一条路径耗费的 体力值 是路径上相邻格子之间 "高度差绝对值" 的 "最大值" 决定的。
请你返回从左上角走到右下角的最小 体力消耗值 。
*/
#ifndef _GRAPH_DIJKSTRA_LEETCODE1631_H_
#define _GRAPH_DIJKSTRA_LEETCODE1631_H_

#include "include_std_c++.h"


struct compare {
    bool operator()(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
        return a.first > b.first;
    }
};

class Solution1631 {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // key: (row, col)
        // value: the vector of (row', col', cost)
        map<vector<int>, vector<vector<int>>> graph;
        // create graph
        for(int row = 0; row < heights.size(); ++row){
            for(int col = 0; col < heights[0].size(); ++col){
                if(row > 0 ){
                   graph[vector<int>{row, col}].emplace_back(vector<int>{row-1, col, abs(heights[row][col] - heights[row-1][col])}); 
                }
                if(row < heights.size() - 1){
                   graph[vector<int>{row, col}].emplace_back(vector<int>{row+1, col, abs(heights[row][col] - heights[row+1][col])}); 
                }
                if(col > 0){
                    graph[vector<int>{row, col}].emplace_back(vector<int>{row, col-1, abs(heights[row][col] - heights[row][col-1])}); 
                }
                if(col < heights[0].size() - 1){
                    graph[vector<int>{row, col}].emplace_back(vector<int>{row, col+1, abs(heights[row][col] - heights[row][col+1])}); 
                }
            }
        }

        // origin : (0,0)
        // destination: (row-1, col-1)
        vector<vector<int>> dis(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, compare> pq;
        dis[0][0] = 0;
        pq.emplace(dis[0][0], vector<int>({0,0}));
        while(true){
            if(pq.empty()){
                return dis.back().back();
            }

            int distance = pq.top().first;
            vector<int> pos = pq.top().second;
            pq.pop();
            if(distance > dis[pos[0]][pos[1]]){
                continue;
            }

            for(auto& x: graph[pos]){
                // Note : dis[x[0]][x[1]] is the maximum cost from (0,0) to (x[0], x[1]) not the sum distance
                if(max(distance, x[2]) < dis[x[0]][x[1]]){
                    dis[x[0]][x[1]] = max(distance, x[2]);
                    pq.emplace(dis[x[0]][x[1]], vector<int>({x[0], x[1]}));
                }
            }
        }
    }
};

void test1631(){
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    Solution1631 solution;
    cout << solution.minimumEffortPath(heights) << endl;
}

#endif // !_GRAPH_DIJKSTRA_LEETCODE1631_H_