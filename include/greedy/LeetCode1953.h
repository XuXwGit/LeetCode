#ifndef _GREEDY_LEETCODE1953_H_
#define _GREEDY_LEETCODE1953_H_

class Solution1953 {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        // 0ll: long long type 0
        long long sums = accumulate(milestones.begin(), milestones.end(), 0ll);
        long long longest = *(max_element(milestones.begin(), milestones.end()));
        long long rest = sums - longest;
        if(longest > rest + 1){
            return 2 * rest + 1;
        }else{
            return sums;
        }
    }
};

void test1953() {
    Solution1953 sol;
    vector<int> milestones = {5, 7, 5, 7};
    cout << sol.numberOfWeeks(milestones) << endl;
}

#endif // !_GREEDY_LEETCODE1953_H_