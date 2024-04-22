/*
39. 组合总和
已解答
中等
相关标签
相关企业
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。
*/

#ifndef _BACKTRACK_LEETCODE39_H_
#define _BACKTRACK_LEETCODE39_H_

class Solution39 {
private:
    void backtrack(vector<int>& candidates, int target, int level, vector<int>& sol, vector<vector<int>>& res){
        if(target < 0){
            return;
        }
        else if(target == 0){
            res.push_back(sol);
            return;
        }

        for(int i = level; i<candidates.size(); ++i){
            sol.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i, sol, res);
            sol.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sol;
        vector<vector<int>> res;
        backtrack(candidates, target, 0, sol, res);

        return res;
    }
};


void test39(){
    Solution39 s;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = s.combinationSum(candidates, target);
    for(auto& v : res){
        for(auto& i : v){
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

#endif // !_BACKTRACK_LEETCODE39_H_