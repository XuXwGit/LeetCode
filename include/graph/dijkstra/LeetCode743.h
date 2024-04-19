/*
743. 网络延迟时间
有 n 个网络节点，标记为 1 到 n。
给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， wi 是一个信号从源节点传递到目标节点的时间。
现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 
*/

#ifndef _LEETCODE_743_H_
#define _LEETCODE_743_H_

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution743 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, vector<pair<int,int>>> graph;
        for(auto& x: times){
            graph[x[0]-1].push_back(pair<int, int>(x[1]-1, x[2]));
        }

        vector<int> distance(n, INT_MAX/2);
        vector<bool> isvisited(n, false);
        distance[k - 1] = 0;
        while(true){
            // find current shortest node
            int curr = -1;
            for(int i = 0; i<n; ++i){
                curr = !isvisited[i] && (curr < 0 || distance[i] < distance[curr]) ? i : curr;
            }

            // all nodes are shortest
            if(curr < 0){
                return *(max_element(distance.begin(), distance.end()));
            }

            if(distance[curr] == INT_MAX/2){
                return -1;
            }

            isvisited[curr] = true;

            for(auto& y : graph[curr]){
                distance[y.first] = min(distance[y.first], distance[curr] + y.second);
            }
        }
    }
};


void test743(){
    Solution743 solution;

    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;
    cout << solution.networkDelayTime(times, n, k) << endl;

    times = {{1,2,1}};
    n = 2;
    k = 2;
    cout << solution.networkDelayTime(times, n, k) << endl;
}

#endif // _LEETCODE_743_H_