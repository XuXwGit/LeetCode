/*

*/
#ifndef _GREEDY_LEETCODE510_H_
#define _GREEDY_LEETCODE510_H_

#include "include_std_c++.h"



#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void splitSubArray(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end(), greater<int>());
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; ++i) {
        if (pq.size() < k) {
            pq.push(nums[i]);
        } else {
            int top = pq.top();
            pq.pop();
            pq.push(top + nums[i]);
        }
    }

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}



void test0510(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 15, 17, 18, 20};
    int k = 5;
    splitSubArray(nums, k);
}

#endif // _GREEDY_LEETCODE510_H_