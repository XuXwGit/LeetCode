/*
请你实现一个 Graph 类：
Graph(int n, int[][] edges) 初始化图有 n 个节点，并输入初始边。
addEdge(int[] edge) 向边集中添加一条边，其中 edge = [from, to, edgeCost] 。数据保证添加这条边之前对应的两个节点之间没有有向边。
int shortestPath(int node1, int node2) 返回从节点 node1 到 node2 的路径 最小 代价。如果路径不存在，返回 -1 。一条路径的代价是路径中所有边代价之和。
*/

#ifndef _GRAPH_DIJKSTRA_LEETCODE2642_H_
#define _GRAPH_DIJKSTRA_LEETCODE2642_H_

class Graph2642 {
private:
    int n;
    map<int, vector<pair<int, int>>> graph;
public:
    Graph2642(int n, std::vector<std::vector<int>>& edges) {
        this->n = n;
        for(auto edge: edges){
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> pq;
        dis[node1] = 0;
        pq.emplace(0, node1);

        while(true){
            if(pq.empty()){
                return dis[node2] == INT_MAX?-1:dis[node2];
            }

            int disx = pq.top().first;
            int curr = pq.top().second;

            pq.pop();
            if(disx > dis[curr]){
                continue;
            }

            for(auto edge: graph[curr]){
                int x = edge.first;
                int cost = edge.second;
                if(dis[curr] + cost < dis[x]){
                    dis[x] = dis[curr] + cost;
                    pq.emplace(dis[x], x);
                }
            }
        }
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

void test2642(){
    vector<vector<int>> edges = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    Graph2642* obj = new Graph2642(3, edges);
    cout << obj->shortestPath(0, 2) << endl;
    obj->addEdge({0, 1, 100});
    cout << obj->shortestPath(0, 2) << endl;
}

#endif // !_GRAPH_DIJKSTRA_LEETCODE2642_H_