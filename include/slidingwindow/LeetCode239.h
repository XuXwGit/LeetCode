/*
239. 滑动窗口最大值
已解答
困难
相关标签
相关企业
提示
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。
*/

#ifndef _MOVEWINDOW_LEETCODE239_H_
#define _MOVEWINDOW_LEETCODE239_H_

class Solution239 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        int left = 0;
        int right = 0;
        while(right < k){
            pq.emplace(nums[right], right);
            right ++;
        }
        res.push_back(pq.top().first);
        while(right<nums.size()){
            pq.emplace(nums[right], right);
            left ++;
            while(pq.top().second < left){
                pq.pop();
            }
            res.push_back(pq.top().first);
            right ++;
        }

        return res;
    }
};

void test239(){
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution239 solution;
    vector<int> res = solution.maxSlidingWindow(nums, k);
    for(auto i : res){
        cout << i << " ";
    }
    cout << endl;
}

#endif  // _MOVEWINDOW_LEETCODE239_H_