/*
1449. 数位成本和为目标值的最大数字
困难
相关标签
相关企业
提示
给你一个整数数组 cost 和一个整数 target 。请你返回满足如下规则可以得到的 最大 整数：

给当前结果添加一个数位（i + 1）的成本为 cost[i] （cost 数组下标从 0 开始）。
总成本必须恰好等于 target 。
添加的数位中没有数字 0 。
由于答案可能会很大，请你以字符串形式返回。

如果按照上述要求无法得到任何整数，请你返回 "0" 。



示例 1：

输入：cost = [4,3,2,5,6,7,2,5,5], target = 9
输出："7772"
解释：添加数位 '7' 的成本为 2 ，添加数位 '2' 的成本为 3 。所以 "7772" 的代价为 2*3+ 3*1 = 9 。 "977" 也是满足要求的数字，但 "7772" 是较大的数字。
 数字     成本
  1  ->   4
  2  ->   3
  3  ->   2
  4  ->   5
  5  ->   6
  6  ->   7
  7  ->   2
  8  ->   5
  9  ->   5
示例 2：

输入：cost = [7,6,5,5,5,6,8,7,8], target = 12
输出："85"
解释：添加数位 '8' 的成本是 7 ，添加数位 '5' 的成本是 5 。"85" 的成本为 7 + 5 = 12 。
示例 3：

输入：cost = [2,4,6,2,4,6,4,4,4], target = 5
输出："0"
解释：总成本是 target 的条件下，无法生成任何整数。
示例 4：

输入：cost = [6,10,15,40,40,40,40,40,40], target = 47
输出："32211"


提示：

cost.length == 9
1 <= cost[i] <= 5000
1 <= target <= 5000
*/

#ifndef _LEETCODE_DP_KNAPNACK_LEETCODE1449_H_
#define _LEETCODE_DP_KNAPNACK_LEETCODE1449_H_

class Solution1449
{
private:
    string sols;
    map<pair<int, int>, int> memo;

    int dfs(int i, const vector<int> &cost, int target, string sol)
    {
        if (target < 0)
        {
            return INT_MIN;
        }
        else if (target == 0)
        {
            cout << sol << endl;
            sort(sol.begin(), sol.end(), greater<>());
            if (sols.size() < sol.size())
            {
                sols = sol;
            }
            else if (sols.size() == sol.size())
            {
                if (sols < sol)
                {
                    sols = sol;
                }
            }
            return 0;
        }

        if (i < 0)
        {
            return INT_MIN;
        }

        pair<int, int> x = {i, target};

        if (memo[x] > 0)
        {
            return memo[x];
        }

        int res1 = dfs(i - 1, cost, target, sol);

        sol.push_back('1' + i);
        int res2 = dfs(i, cost, target - cost[i], sol) + 1;
        sol.pop_back();

        memo[x] = max(res1, res2);

        return memo[x];
    }

public:
    string largestNumber(vector<int> &cost, int target)
    {
        string str = "";
        dfs(cost.size() - 1, cost, target, str);
        return str;
    }
};

void test1449()
{
    Solution1449 solution1449;
    vector<int> cost = {4, 3, 2, 5, 6, 7, 2, 5, 5};
    int target = 9;
    cout << solution1449.largestNumber(cost, target) << endl;
    target = 12;
    cout << solution1449.largestNumber(cost, target) << endl;
}

#endif // !_LEETCODE_DP_KNAPNACK_LEETCODE1449_H_