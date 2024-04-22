/*
684. 冗余连接

树可以看成是一个连通且 无环 的 无向 图。

给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。

请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的那个。
*/

#ifndef _GRAPH_UNION_FIND_LEETCODE684_H_
#define _GRAPH_UNION_FIND_LEETCODE684_H_


class Solution684 {
private:
    vector<int> parent;
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        set<int> nodes;
        for(auto& x: edges){
            nodes.insert(x[0]);
            nodes.insert(x[1]);
        }

        int n = nodes.size();

        parent = vector<int>(n);
        for(int i = 0; i<n; ++i){
            parent[i] = i;
        }

        for(auto x: edges){
            int parent_a = find(x[0]);
            int parent_b = find(x[1]);
            if(find(parent_a) != find(parent_b)){
                parent[parent_b] = parent_a; 
            }else{
                return x;
            }
        }

        return {};
    }
};

void test684(){
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    Solution684 s;
    vector<int> res = s.findRedundantConnection(edges);
    for(auto x: res){
        cout << x << " ";
    }
    cout << endl;

    edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    res = s.findRedundantConnection(edges);
    for(auto x: res){
        cout << x << " ";
    }
    cout << endl;

    edges = {{3, 4}, {1, 2}, {2, 4}, {3, 5}, {2, 5}};
    res = s.findRedundantConnection(edges);
    for(auto x: res){
        cout << x << " ";
    }
    cout << endl;

}

#endif // !_GRAPH_UNION_FIND_LEETCODE684_H_