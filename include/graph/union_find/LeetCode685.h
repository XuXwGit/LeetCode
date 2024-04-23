/*
685. 冗余连接 II
困难

在本问题中，有根树指满足以下条件的 有向 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。

输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。附加的边包含在 1 到 n 中的两个不同顶点间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是 vi 的一个父节点。

返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
*/

#ifndef _GRAPH_UNION_FIND_LEETCODE685_H_
#define _GRAPH_UNION_FIND_LEETCODE685_H_

class Solution685 {
private:
    vector<int> parent;
    vector<int> pre;
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void connect(int x, int y){
        int p_x = find(x);
        int p_y = find(y);
        if(p_x == p_y){
            return;
        }else{
            parent[p_x] = p_y;
            return;
        }
    }
    bool isconnected(int x, int y){
        return find(x) == find(y);
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent = vector<int>(n + 1);
        pre = vector<int>(n + 1);
        for(int i = 1; i<=n; ++i){
            parent[i] = i;
            pre[i] = i;
        }

        int confict = -1;
        int cycle = -1;
        for(int i = 0; i<edges.size(); ++i){
            if(pre[edges[i][1]] != edges[i][1]){
                confict = i;
            }else{
                pre[edges[i][1]] = edges[i][0];
                if(isconnected(edges[i][0], edges[i][1])){
                    cycle = i;
                }else{
                    connect(edges[i][0], edges[i][1]);
                }
            }
        }

        if(confict < 0){
            return edges[cycle];
        }else{
            if(cycle < 0){
                return edges[confict];
            }else{
                return vector<int>{pre[edges[confict][1]], edges[confict][1]};
            }
        }
    }
};


void test685(){
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    Solution685 s;
    vector<int> res = s.findRedundantDirectedConnection(edges);
    for(auto x: res){
        cout << x << " ";
    }
    cout << endl;

    edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    res = s.findRedundantDirectedConnection(edges);
    for(auto x: res){
        cout << x << " ";
    }
    cout << endl;

    edges = {{3, 4}, {1, 2}, {2, 4}, {3, 5}, {2, 5}};
    res = s.findRedundantDirectedConnection(edges);
    for(auto x: res){
        cout << x << " ";
    }
    cout << endl;
}


#endif // !_GRAPH_UNION_FIND_LEETCODE685_H_