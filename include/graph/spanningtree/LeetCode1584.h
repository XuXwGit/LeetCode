/*
1584. 连接所有点的最小费用

给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。

连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 val 的绝对值。

请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。
*/

#ifndef _GRAPH_SPANNINGTREE_LEETCODE1584_H_
#define _GRAPH_SPANNINGTREE_LEETCODE1584_H_


class Solution1584 {
private:
    struct edge{
        int a;
        int b;
        int weight;
        bool operator<(const edge& rhs){
            return weight < rhs.weight;
        }
        edge(int a, int b, int weight):a(a), b(b), weight(weight){}
    };
    vector<int> parent;

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    int prim(int n, vector<vector<int>>& distance){
        int res = 0;

        vector<int> set_distance(n, INT_MAX);
        vector<bool> inset(n, false);
        
        set_distance[0] = 0;
        for(int i = 0; i<n; ++i){
            int curr = -1;
            for(int j = 0; j < n; ++j){
                if(!inset[j] && (curr == -1 || set_distance[curr] > set_distance[j])){
                    curr = j;
                }
            }

            inset[curr] = true;

            if(set_distance[curr] == INT_MAX){
                return INT_MAX;
            }else{
                res += set_distance[curr];
            }

            for(int j = 0; j<n; ++j){
                set_distance[j] = min(set_distance[j], distance[curr][j]);
            }
        }

        return res;
    }

    int kruskal(int n, vector<edge>& edges){
        sort(edges.begin(), edges.end());

        parent = vector<int>(n);
        for(int i = 0; i<n; ++i){
            parent[i] = i;
        }

        int res = 0;
        int count = 0;
        for(const auto& edge: edges){
            int a = edge.a;
            int b = edge.b;
            int weight = edge.weight;

            a = find(a);
            b = find(b);
            if(a != b){
                parent[b] = a;
                res += weight;
                count ++;
            }
        }

        return count < n-1? INT_MAX: res;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> distance(n, vector<int>(n, 0));
        vector<edge> edges;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                distance[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                if(i != j)
                    edges.emplace_back(i, j, distance[i][j]);
            }
        }

        // return prim(n, distance);
        return kruskal(n, edges);
    }
};

void test1584(){
    Solution1584 s;
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << s.minCostConnectPoints(points) << endl;
    points = {{3,12},{-2,5},{-4,1}};
    cout << s.minCostConnectPoints(points) << endl;
    points = {{0,0},{1,1},{1,0},{-1,1}};
    cout << s.minCostConnectPoints(points) << endl;
    points = {{-1000000,-1000000},{1000000,1000000}};
    cout << s.minCostConnectPoints(points) << endl;
}

#endif // !_GRAPH_SPANNINGTREE_LEETCODE1584_H_