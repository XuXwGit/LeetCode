#ifndef _LEETCODE_239_
#define _LEETCODE_239_

#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;
class Solution239 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;

        int maxWin = 0;
        priority_queue<pair<int, int>> pri_que;
        for (int i = 0; i < k; ++i) {
            pri_que.push(pair<int, int>(nums[i], i));
        }

        for (int i = k; i < nums.size(); i++) {
            res.push_back(pri_que.top().first);
            
            while (!pri_que.empty()&& pri_que.top().second <= i - k ) {
                pri_que.pop();
            }

            pri_que.push(pair<int, int>(nums[i], i));
        }
        res.push_back(pri_que.top().first);
        return res;
    }
};

#endif // !_LEETCODE_239_
