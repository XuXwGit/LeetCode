/*
399. 除法求值

给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。

另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。

返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。

注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。

注意：未在等式列表中出现的变量是未定义的，因此无法确定它们的答案。
*/

// Sovle Methods:
// 1. Floyd Algorithm
// 2. Union Find Set

#define _USE_FLOYD_399_

#ifndef _GRAPH_FLOYD_LEETCODE399_H_
#define _GRAPH_FLOYD_LEETCODE399_H_


#include <float.h>

#ifdef _USE_FLOYD_399_

class Solution399 {
private:
    void floyd(map<string, int>& index_dir, vector<vector<double>>& distances){
        for(auto k: index_dir){
            for(auto i : index_dir){
                if(i.second==k.second){
                    continue;
                }
                for(auto j : index_dir){
                    if(j.second==i.second || j.second==k.second){
                        continue;
                    }
                    if(distances[i.second][k.second] == DBL_MAX || distances[k.second][j.second] == DBL_MAX){
                        continue;
                    }
                    if(distances[i.second][j.second] > distances[i.second][k.second] * distances[k.second][j.second])
                        distances[i.second][j.second] = distances[i.second][k.second] * distances[k.second][j.second];
                }
            }
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = 0;
        map<string, int> index_dir;
        map<string, vector<pair<string, double>>> graph;
        for(int i = 0; i<equations.size(); ++i){
            if(!index_dir.count(equations[i][0])){
                index_dir[equations[i][0]] = n;
                n++;
            }
            if(!index_dir.count(equations[i][1])){
                index_dir[equations[i][1]] = n;
                n++;
            }
        }

        vector<vector<double>> distances(n, vector<double>(n, DBL_MAX));
        for(int i = 0; i<n; ++i){
            distances[i][i] = 1.0;
        }
        
        for(int i = 0; i<equations.size(); ++i){
            distances[index_dir[equations[i][0]]][index_dir[equations[i][1]]] = values[i];
            distances[index_dir[equations[i][1]]][index_dir[equations[i][0]]] = 1.0/values[i];
        }

        floyd(index_dir, distances);

        vector<double> res(queries.size());
        for(int i = 0; i<queries.size(); ++i){
            if(index_dir.count(queries[i][0]) && index_dir.count(queries[i][1])){
                if(distances[index_dir[queries[i][0]]][index_dir[queries[i][1]]] < DBL_MAX){
                    res[i] = distances[index_dir[queries[i][0]]][index_dir[queries[i][1]]];
                }else{
                    res[i] = -1.0;
                }
            }else{
                res[i] = -1.0;
            }
        }

        return res;
    }
};


#else

class Solution339 {
private:
    vector<int> parent;
    vector<double> weights;
    int find(int x){
        if(x != parent[x]){
            int origin = parent[x];
            parent[x] = find(parent[x]);
            weights[x] *= weights[origin];
        }

        return parent[x];
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = 0;
        map<string, int> index_dir;
        for(int i = 0; i<equations.size(); ++i){
            if(!index_dir.count(equations[i][0])){
                index_dir[equations[i][0]] = n;
                n++;
            }
            if(!index_dir.count(equations[i][1])){
                index_dir[equations[i][1]] = n;
                n++;
            }
        }

        this->parent = vector<int>(n);
        this->weights = vector<double>(n,1.0);
        for(int i = 0; i<n; ++i){
            parent[i] = i;
        }

        for(int i = 0; i<equations.size(); ++i){
            int a = index_dir[equations[i][0]];
            int b = index_dir[equations[i][1]];
            double weight = values[i];
            
            int parent_a = find(a);
            int parent_b = find(b);
            if(parent_a == parent_b){
                continue;
            }
            parent[parent_a] = parent_b;
            weights[parent_a] = weights[b] * weight / weights[a];
        }

        vector<double> res(queries.size());
        for(int i = 0; i<queries.size(); ++i){
            if(index_dir.count(queries[i][0]) && index_dir.count(queries[i][1])){
                int a = index_dir[queries[i][0]];
                int b = index_dir[queries[i][1]];
                if(find(a) != find(b)){
                    res[i] = -1.0;
                }else{
                    res[i] = (weights[a] / weights[b]);
                }
            }else{
                res[i] = -1.0;
            }
        }

        return res;
    }
};

#endif

void test399(){
    // equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
    // Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    Solution399 s;
    vector<double> res = s.calcEquation(equations, values, queries);
    for(auto r: res){
        cout<<r<<", ";
    }
    cout<<endl;
}

#endif // _GRAPH_FLOYD_LEETCODE399_H_