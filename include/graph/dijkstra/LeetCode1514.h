/*
1514. 概率最大的路径
给你一个由 n 个节点（下标从 0 开始）组成的无向加权图，该图由一个描述边的列表组成，其中 edges[i] = [a, b] 表示连接节点 a 和 b 的一条无向边，且该边遍历成功的概率为 succProb[i] 。
指定两个节点分别作为起点 start 和终点 end ，请你找出从起点到终点成功概率最大的路径，并返回其成功概率。
如果不存在从 start 到 end 的路径，请 返回 0 。只要答案与标准答案的误差不超过 1e-5 ，就会被视作正确答案。
*/

#ifndef _GRAPH_DIJKSTRA_LEETCODE1514_H_
#define _GRAPH_DIJKSTRA_LEETCODE1514_H_


class Solution1514 {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        map<int, vector<pair<int, double>>> graph;
        for(int i = 0; i<edges.size(); ++i){
            // non-direct graph
            graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        
        vector<double> dis(n, 1e-5);
        priority_queue<pair<double, int>> pq;
        dis[start_node] = 1.0;
        pq.emplace(1.0, start_node);
        
        while(true){
            if(pq.empty()){
                return dis[end_node] <= 1e-5? 0 : dis[end_node];
            }

            double prob = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            if(prob < dis[curr]){
                continue;
            }

            for(auto x: graph[curr]){
                int destination = x.first;
                double probility = x.second;
                if(probility * prob > dis[destination]){
                    dis[destination] = probility * prob;
                    pq.emplace(dis[destination], destination);
                }
            }
        }
    }
};


void test1514(){
    // n = 5
    // [[1,4],[2,4],[0,4],[0,3],[0,2],[2,3]]
    // [0.37,0.17,0.93,0.23,0.39,0.04]
    // 3 -> 4
    int n = 5;
    vector<vector<int>> edges = {{1,4},{2,4},{0,4},{0,3},{0,2},{2,3}};
    vector<double> succProb = {0.37,0.17,0.93,0.23,0.39,0.04};
    int start_node = 3;
    int end_node = 4;
    Solution1514 solution;
    cout << solution.maxProbability(n, edges, succProb, start_node, end_node) << endl; // 0.21390
}


#endif // !_GRAPH_DIJKSTRA_LEETCODE1514_H_