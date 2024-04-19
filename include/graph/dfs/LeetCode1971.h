/*
1971. 寻找图中是否存在路径
请你确定是否存在从顶点 source 开始，到顶点 destination 结束的 有效路径 。
*/

#ifndef _LEETCODE_1971_H_
#define _LEETCODE_1971_H_

class Solution1971 {
private:
    int n;
    vector<bool> isvisited;
    map<int, vector<int>> graph;
    void dfs(int i, int j, bool& flag){
        if(i == j){
            flag = true;
            return;
        }

        if(isvisited[i]){
            return;
        }

        isvisited[i] = true;

        for(int k : graph[i]){
            if(!isvisited[k]){
                dfs(k, j, flag);
            }
            if(flag){
                return;
            }
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        this->isvisited = vector<bool>(n, false);
        this->n = n;

        for(auto x: edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }

        bool flag = false;

        dfs(source, destination, flag);

        return flag;
    }
};

void test1971(){
    Solution1971 solution;

    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    cout << solution.validPath(3, edges, 0, 2) << endl;

    edges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}};
    cout << solution.validPath(6, edges, 0, 5) << endl;
}

#endif // !_LEETCODE_1971_H_