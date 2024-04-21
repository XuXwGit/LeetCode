/*
1489. 找到最小生成树里的关键边和伪关键边
困难

给你一个 n 个点的带权无向连通图，节点编号为 0 到 n-1 ，同时还有一个数组 edges ，其中 edges[i] = [fromi, toi, weighti] 表示在 fromi 和 toi 节点之间有一条带权无向边。最小生成树 (MST) 是给定图中边的一个子集，它连接了所有节点且没有环，而且这些边的权值和最小。

请你找到给定图中最小生成树的所有关键边和伪关键边。如果从图中删去某条边，会导致最小生成树的权值和增加，那么我们就说它是一条关键边。伪关键边则是可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。

请注意，你可以分别以任意顺序返回关键边的下标和伪关键边的下标
*/


#ifndef _GRAPH_SPANNINGTREE_LEETCODE1489_H_
#define _GRAPH_SPANNINGTREE_LEETCODE1489_H_


class Solution1489 {
private:
    struct edge{
        int index;
        int a;
        int b;
        int weight;
        bool operator<(const edge& rhs){
            return weight < rhs.weight;
        }
        edge(int index, int a, int b, int weight):index(index), a(a), b(b), weight(weight){}
    };

    vector<int> parent;
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    int kruskal(int n, vector<edge>& edges, int ignore){
        int res = 0;

        parent = vector<int>(n);
        for(int i = 0; i<n; ++i){
            parent[i] = i;
        }

        int count = 0;
        for(int i = 0; i<edges.size(); ++i){
            if(i == ignore){
                continue;
            }
            struct edge edge = edges[i];
            int a = find(edge.a);
            int b = find(edge.b);
            if(a != b){
                parent[a] = b;
                res += edge.weight;;
                count ++;
            }
        }

        return count < n-1? INT_MAX: res;
    }

    bool idPseudoEdge(int n, vector<edge>& edges, int ignore, int min_cost){
        parent = vector<int>(n);
        for(int i = 0; i<n; ++i){
            parent[i] = i;
        }

        int res = edges[ignore].weight;
        parent[edges[ignore].a] = edges[ignore].b;

        int count = 1;
        for(int i = 0; i<edges.size(); ++i){
            if(i == ignore){
                continue;
            }
            struct edge edge = edges[i];
            int a = find(edge.a);
            int b = find(edge.b);
            if(a != b){
                parent[a] = b;
                res += edge.weight;;
                count ++;
            }
        }

        return res == min_cost;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<edge> edgeset;
        for(int i = 0; i<edges.size(); ++i){
            edgeset.emplace_back(i, edges[i][0], edges[i][1], edges[i][2]);
        }
        sort(edgeset.begin(), edgeset.end());
        int min_cost = kruskal(n, edgeset, -1);

        vector<int> keyedges;
        vector<int> pesudoedges;
        for(int i = 0; i<edgeset.size(); ++i){
            int cost = kruskal(n, edgeset, i);
            if(cost > min_cost){
                keyedges.push_back(edgeset[i].index);
            }else{
                // check if pseudo edge
                if(idPseudoEdge(n, edgeset, i, min_cost))
                    pesudoedges.push_back(edgeset[i].index);
            }
        }
        vector<vector<int>> res;
        res.push_back(keyedges);
        res.push_back(pesudoedges);

        return res;
    }
};

void test1489(){
    Solution1489 s;
    vector<vector<int>> edges = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};
    vector<vector<int>> res = s.findCriticalAndPseudoCriticalEdges(5, edges);
    for(auto x: res){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }

    // n=6
    // [[0,1,1],[1,2,1],[0,2,1],[2,3,4],[3,4,2],[3,5,2],[4,5,2]]
    // Output: [[3],[0,1,2,4,5,6]]
    edges = {{0,1,1},{1,2,1},{0,2,1},{2,3,4},{3,4,2},{3,5,2},{4,5,2}};
    res = s.findCriticalAndPseudoCriticalEdges(6, edges);
    for(auto x: res){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }
}

#endif // !_GRAPH_SPANNINGTREE_LEETCODE1489_H_