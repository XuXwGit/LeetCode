/*
924. 尽量减少恶意软件的传播
给出了一个由 n 个节点组成的网络，用 n × n 个邻接矩阵图 graph 表示。在节点网络中，当 graph[i][j] = 1 时，表示节点 i 能够直接连接到另一个节点 j。 
一些节点 initial 最初被恶意软件感染。只要两个节点直接连接，且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。
假设 M(initial) 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。
如果从 initial 中移除某一节点能够最小化 M(initial)， 返回该节点。如果有多个节点满足条件，就返回索引最小的节点。
请注意，如果某个节点已从受感染节点的列表 initial 中删除，它以后仍有可能因恶意软件传播而受到感染。
*/

#ifndef  _LEETCODE_924_H_
#define  _LEETCODE_924_H_

class Solution924 {
private:
    vector<vector<int>> graph;
    unordered_set<int> initial_set;
    vector<bool> isvisited;
    int size = 0;
    int node_id = -1;
    int dfs(int i){
        isvisited[i] = true;
        size ++;
        if(initial_set.count(i)){
            node_id = node_id == -1? i : -2;
        }
        for(int j = 0; j<graph.size(); ++j){
            if(graph[i][j] && !isvisited[j])
                dfs(j);
        }
        return size;
    }
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        this->graph = graph;
        this->isvisited = vector<bool>(graph.size(), false);
        this->initial_set;

        for(int x: initial){
            initial_set.insert(x);
        }
        
        int ans = -1;
        int max_size = 0;

        for(int i: initial){
            if(isvisited[i]){
                continue;
            }
            
            node_id = -1;
            size = 0;

            dfs(i);
            
            if (node_id >= 0 && (size > max_size || size == max_size && node_id < ans)) {
                ans = node_id;
                max_size = size;
            }

        }

        return ans < 0 ? *std::min_element(initial.begin(), initial.end()) : ans;
    }
};

void test924(){
    // [[1,0,0,0,0,0],[0,1,1,0,0,0],[0,1,1,0,0,0],[0,0,0,1,1,1],[0,0,0,1,1,1],[0,0,0,1,1,1]]
    // [2,3]
    vector<vector<int>> graph = {{1,0,0,0,0,0},{0,1,1,0,0,0},{0,1,1,0,0,0},{0,0,0,1,1,1},{0,0,0,1,1,1},{0,0,0,1,1,1}};
    vector<int> initial = {2, 3};
    Solution924 s;
    cout << s.minMalwareSpread(graph, initial) << endl;

}


#endif // _LEETCODE_924_H_