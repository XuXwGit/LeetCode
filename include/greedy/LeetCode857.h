/*
857. 雇佣 K 名工人的最低成本

有 n 名工人。 给定两个数组 quality 和 wage ，其中，quality[i] 表示第 i 名工人的工作质量，其最低期望工资为 wage[i] 。

现在我们想雇佣 k 名工人组成一个工资组。在雇佣 一组 k 名工人时，我们必须按照下述规则向他们支付工资：

对工资组中的每名工人，应当按其工作质量与同组其他工人的工作质量的比例来支付工资。
工资组中的每名工人至少应当得到他们的最低期望工资。
给定整数 k ，返回 组成满足上述条件的付费群体所需的最小金额 。在实际答案的 10-5 以内的答案将被接受。。
*/

#ifndef _LEETCODE857_H_
#define _LEETCODE857_H_

class Solution857 {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        int n = quality.size();
        vector<pair<double, int>> average_wage;
        for (int i = 0; i < n; ++i) {
            average_wage.emplace_back((double)wage[i] / quality[i], quality[i]);
        }
        sort(average_wage.begin(), average_wage.end());

        double total = 0;
        double min_cost = DBL_MAX;
        priority_queue<int> pq;
        for (int i = 0; i < k; ++i) {
            pq.emplace(average_wage[i].second);
            total += average_wage[i].second;
        }
        min_cost = total * average_wage[k-1].first;
        for (int i = k; i < n; ++i) {
            if (average_wage[i].second < pq.top()) {
                int dec = pq.top() - average_wage[i].second;
                // Note: if we use the following condition, the result will be wrong, "total" record the minimum total quality
                // if (min_cost > (total - dec) * average_wage[i].first) {
                    total = total - dec;
                    min_cost = total * average_wage[i].first;
                    pq.pop();
                    pq.emplace(average_wage[i].second);
                // }
            }
        }

        return min_cost;
    }
};

void test857(){
    Solution857 s;
    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    int k = 2;
    cout << s.mincostToHireWorkers(quality, wage, k) << endl;

    quality = {3, 1, 10, 10, 1};
    wage = {4, 8, 2, 2, 7};
    k = 3;
    cout << s.mincostToHireWorkers(quality, wage, k) << endl;

    // [32,43,66,9,94,57,25,44,99,19]
    // [187,366,117,363,121,494,348,382,385,262]
    // 4
    quality = {32,43,66,9,94,57,25,44,99,19};
    wage = {187,366,117,363,121,494,348,382,385,262};
    k = 4;
    cout << s.mincostToHireWorkers(quality, wage, k) << endl;
}

#endif // _LEETCODE857_H_