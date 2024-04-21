/*
216. 组合总和 III

找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
*/

#ifndef _BACKTRACK_LEETCODE216_H_
#define _BACKTRACK_LEETCODE216_H_


class Solution216 {
private:
    void backtrack(int k, int target, int level, vector<int>& sol, vector<vector<int>>& res){
        if(target < 0){
            return;
        }
        else if(target == 0 && k==0){
            res.push_back(sol);
            return;
        }

        if(k<=0 || level >= 10){
            return;
        }

        sol.push_back(level);
        backtrack(k-1, target-level, level+1, sol, res);
        sol.pop_back();
        backtrack(k, target, level+1, sol, res);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> sol;

        backtrack(k, n, 1, sol, res);

        return res;
    }
};


void test216(){
    Solution216 s;
    int k = 3;
    int n = 9;
    vector<vector<int>> res = s.combinationSum3(k, n);
    for(auto& v : res){
        for(auto& i : v){
            cout << i << " ";
        }
        cout << endl;
    }
}

#endif // !_BACKTRACK_LEETCODE216_H_