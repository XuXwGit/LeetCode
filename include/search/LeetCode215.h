/*
215. 数组中的第K个最大元素
已解答
中等
相关标签
相关企业
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/

#ifndef _SEARCH_LEETCODE215_H_
#define _SEARCH_LEETCODE215_H_

class Solution215 {
private:
    int quickSelect(vector<int>& nums, int k){
        int n = nums.size();
        int base = nums[rand() % n];

        vector<int> less;
        vector<int> equal;
        vector<int> greater;

        for(auto x: nums){
            if(x > base){
                greater.push_back(x);
            }else if(x == base){
                equal.push_back(x);
            }else{
                less.push_back(x);
            }
        }

        if(greater.size() >= k){
            return quickSelect(greater, k);
        }else if(greater.size() + equal.size() >= k){
            return base;
        }else{
            return quickSelect(less, k - (greater.size() + equal.size()));
        }
    }
public:
    // O(n log(n))
    // int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size()-k];
    // }

    // int findKthLargest(vector<int>& nums, int k){
    //     priority_queue<int> pq;
    //     for(auto x: nums){
    //         pq.push(x);
    //     }

    //     for(int i = 0; i<k-1; ++i){
    //         pq.pop();
    //     }

    //     return pq.top();
    // }

    int findKthLargest(vector<int>& nums, int k){
        return quickSelect(nums, k);
    }
};


void test215(){
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    Solution215 solution;
    cout << solution.findKthLargest(nums, k) << endl;
    cout << solution.findKthLargest(nums, 3) << endl;
}

#endif // _SEARCH_LEETCODE215_H_