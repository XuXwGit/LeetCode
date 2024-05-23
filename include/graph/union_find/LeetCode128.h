/*
128. 最长连续序列
已解答
中等

给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

*/


#ifndef _GRAPH_UNION_FIND_LEETCODE128_H_
#define _GRAPH_UNION_FIND_LEETCODE128_H_


class Solution128 {
private:
    vector<int> parents;
    vector<int> counts;

    int find(int x)
    {
        if (parents[x] != x)
        {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }
    void unionSet(int x, int y)
    {
        int p_x = find(x);
        int p_y = find(y);
        if (p_x != p_y)
        {
            parents[p_y] = p_x;
            counts[p_x] += counts[p_y];
        }
    }

public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int n = nums.size();
        parents = vector<int>(n);
        counts = vector<int>(n, 1);

        for (int i = 0; i < n; ++i)
        {
            parents[i] = i;
        }

        unordered_map<int, int> maps;
        for (int i = 0; i < n; ++i)
        {
            maps.emplace(nums[i], i);
        }

        for (auto [x, i] : maps)
        {
            if (maps.count(x - 1))
            {
                unionSet(i, maps[x - 1]);
            }
        }

        return *(max_element(counts.begin(), counts.end()));
    }
};

void test128(){
    Solution128 s;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(nums) << endl;

    // [1,2,0,1]
    nums = {1, 2, 0, 1};
    cout << s.longestConsecutive(nums) << endl;
}

#endif // _GRAPH_UNION_FIND_LEETCODE128_H_