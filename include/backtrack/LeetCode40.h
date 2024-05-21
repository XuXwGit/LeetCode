/*
40. 组合总和 II

给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。 
*/


#ifndef _BACKTRACK_LEETCODE40_H_
#define _BACKTRACK_LEETCODE40_H_


class Solution40 {
private:
    void backtrack(vector<int>& candidates, int target, int level, vector<int>& sol, vector<vector<int>>& res){
        if(target < 0 ){
            return;
        }
        else if(target == 0){
            res.push_back(sol);
            return;
        }

        if(level >= candidates.size()){
            return;
        }

        for(int i = level; i<candidates.size(); ++i){
            if(i>level && candidates[i] == candidates[i-1]){
                continue;
            }
            sol.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i+1, sol, res);
            sol.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> sol;
        vector<vector<int>> res;
        backtrack(candidates, target, 0, sol, res);

        return res;
    }
};

void test40(){
    Solution40 s;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = s.combinationSum2(candidates, target);
    for(auto& v : res){
        for(auto& i : v){
            cout << i << " ";
        }
        cout << endl;
    }

}

#endif // !_BACKTRACK_LEETCODE40_H_
