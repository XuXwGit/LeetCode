/*
2391. 收集垃圾的最少总时间
已解答
中等
相关标签
相关企业
提示
给你一个下标从 0 开始的字符串数组 garbage ，其中 garbage[i] 表示第 i 个房子的垃圾集合。garbage[i] 只包含字符 'M' ，'P' 和 'G' ，但可能包含多个相同字符，每个字符分别表示一单位的金属、纸和玻璃。垃圾车收拾 一 单位的任何一种垃圾都需要花费 1 分钟。

同时给你一个下标从 0 开始的整数数组 travel ，其中 travel[i] 是垃圾车从房子 i 行驶到房子 i + 1 需要的分钟数。

城市里总共有三辆垃圾车，分别收拾三种垃圾。每辆垃圾车都从房子 0 出发，按顺序 到达每一栋房子。但它们 不是必须 到达所有的房子。

任何时刻只有 一辆 垃圾车处在使用状态。当一辆垃圾车在行驶或者收拾垃圾的时候，另外两辆车 不能 做任何事情。

请你返回收拾完所有垃圾需要花费的 最少 总分钟数。
*/

#ifndef _OTHERS_LEETCODE2391_H_
#define _OTHERS_LEETCODE2391_H_

class Solution2391 {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        vector<int> count_M(n, 0);
        vector<int> count_P(n, 0);
        vector<int> count_G(n, 0);

        for(int i = 0; i<n; ++i){
            string s = garbage[i];
            for(auto& x: s){
                if(x == 'M'){
                    count_M[i] ++;
                }else if(x == 'P'){
                    count_P[i] ++;
                }else{
                    count_G[i] ++;
                }
            }
        }

        int res = accumulate(count_M.begin(), count_M.end(), 0)
                + accumulate(count_P.begin(), count_P.end(), 0)
                + accumulate(count_G.begin(), count_G.end(), 0);

        int r_M = n-1, r_P = n-1, r_G = n-1;
        while(r_M >= 0 && !count_M[r_M]){
            r_M --;
        }
        if(r_M > 0)   res += accumulate(travel.begin(), travel.begin() + r_M, 0);

        while(r_P >= 0 && !count_P[r_P]){
            r_P --;
        }
        if(r_P > 0)   res += accumulate(travel.begin(), travel.begin() + r_P, 0);

        while(r_G >= 0 && !count_G[r_G]){
            r_G --;
        }
        if(r_G > 0)   res += accumulate(travel.begin(), travel.begin() + r_G, 0);
        
        return res;
    }
};


void test2391(){
    vector<string> garbage = {"MGP", "PPM", "PPG"};
    vector<int> travel = {2, 3, 1};
    Solution2391 solution;
    cout << solution.garbageCollection(garbage, travel) << endl;
}


#endif // !_OTHERS_LEETCODE2391_H_