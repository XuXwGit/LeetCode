/*
3040. 相同分数的最大操作数目 II
中等
相关标签
相关企业
提示
给你一个整数数组 nums ，如果 nums 至少 包含 2 个元素，你可以执行以下操作中的 任意 一个：

选择 nums 中最前面两个元素并且删除它们。
选择 nums 中最后两个元素并且删除它们。
选择 nums 中第一个和最后一个元素并且删除它们。
一次操作的 分数 是被删除元素的和。

在确保 所有操作分数相同 的前提下，请你求出 最多 能进行多少次操作。

请你返回按照上述要求 最多 可以进行的操作次数。



示例 1：

输入：nums = [3,2,1,2,3,4]
输出：3
解释：我们执行以下操作：
- 删除前两个元素，分数为 3 + 2 = 5 ，nums = [1,2,3,4] 。
- 删除第一个元素和最后一个元素，分数为 1 + 4 = 5 ，nums = [2,3] 。
- 删除第一个元素和最后一个元素，分数为 2 + 3 = 5 ，nums = [] 。
由于 nums 为空，我们无法继续进行任何操作。
示例 2：

输入：nums = [3,2,6,1,4]
输出：2
解释：我们执行以下操作：
- 删除前两个元素，分数为 3 + 2 = 5 ，nums = [6,1,4] 。
- 删除最后两个元素，分数为 1 + 4 = 5 ，nums = [6] 。
至多进行 2 次操作。


提示：

2 <= nums.length <= 2000
1 <= nums[i] <= 1000
*/

#ifndef _LEETCODE_DYNAMIC_RANGE_DP_LEETCODE3040_H_
#define _LEETCODE_DYNAMIC_RANGE_DP_LEETCODE3040_H_

class Solution3040
{
private:
    unordered_map<int, vector<vector<int>>> mem;
    int dfs(int i, int j, const vector<int> &nums, int target)
    {
        if (i >= j)
        {
            return 0;
        }

        if (mem[target][i][j] >= 0)
        {
            return mem[target][i][j];
        }

        int res = 0;
        if (nums[i] + nums[i + 1] == target)
        {
            res = max(res, dfs(i + 2, j, nums, target) + 1);
        }

        if (nums[i] + nums[j] == target)
        {
            res = max(res, dfs(i + 1, j - 1, nums, target) + 1);
        }

        if (nums[j - 1] + nums[j] == target)
        {
            res = max(res, dfs(i, j - 2, nums, target) + 1);
        }

        mem[target][i][j] = res;

        return res;
    }

public:
    int maxOperations(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0;
        mem[nums[0] + nums[1]] = vector<vector<int>>(n, vector<int>(n, -1));
        mem[nums[n - 2] + nums[n - 1]] = vector<vector<int>>(n, vector<int>(n, -1));
        mem[nums[0] + nums[n - 1]] = vector<vector<int>>(n, vector<int>(n, -1));
        int res1 = dfs(2, n - 1, nums, nums[0] + nums[1]) + 1;
        int res2 = dfs(0, n - 3, nums, nums[n - 2] + nums[n - 1]) + 1;
        int res3 = dfs(1, n - 2, nums, nums[0] + nums[n - 1]) + 1;
        res = max({res1, res2, res3});
        return res;
    }
};
void test3040()
{
    vector<int> nums = {3, 2, 1, 2, 3, 4};
    Solution3040 solution3040;
    cout << solution3040.maxOperations(nums) << endl;
    nums = {3, 2, 6, 1, 4};
    cout << solution3040.maxOperations(nums) << endl;
}

#endif // !_LEETCODE_DYNAMIC_RANGE_DP_LEETCODE3040_H_