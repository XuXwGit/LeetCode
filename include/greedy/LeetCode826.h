/*
826. 安排工作以达到最大收益
已解答
中等

你有 n 个工作和 m 个工人。给定三个数组： difficulty, profit 和 worker ，其中:

difficulty[i] 表示第 i 个工作的难度，profit[i] 表示第 i 个工作的收益。
worker[i] 是第 i 个工人的能力，即该工人只能完成难度小于等于 worker[i] 的工作。
每个工人 最多 只能安排 一个 工作，但是一个工作可以 完成多次 。

举个例子，如果 3 个工人都尝试完成一份报酬为 $1 的同样工作，那么总收益为 $3 。如果一个工人不能完成任何工作，他的收益为 $0 。
返回 在把工人分配到工作岗位后，我们所能获得的最大利润 。
*/

#ifndef _GREEDY_LEETCODE826_H_
#define _GREEDY_LEETCODE826_H_


class Solution826 {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int, int>> works;
        for(int i = 0; i<difficulty.size(); ++i){
            works.emplace(profit[i], difficulty[i]);
        }

        sort(worker.begin(), worker.end(), greater<int>());

        int res = 0;
        for(int i = 0; i<worker.size(); ++i){
            while(!works.empty() && works.top().second > worker[i]){
                works.pop();
            }
            if(!works.empty()){
                res += works.top().first;
            }
        }

        return res;
    }
};

void test826(){
    Solution826 sol;
    vector<int> difficulty = {2, 4, 6, 8, 10};
    vector<int> profit = {10, 20, 30, 40, 50};
    vector<int> worker = {4, 5, 6, 7};
    cout << sol.maxProfitAssignment(difficulty, profit, worker) << endl;
}

#endif // !_GREEDY_LEETCODE826_H_