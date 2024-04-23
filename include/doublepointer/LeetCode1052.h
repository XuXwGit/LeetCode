/*
1052. 爱生气的书店老板
*/

#ifndef _MOVE_WINDOWS_LEETCODE1052_H_
#define _MOVE_WINDOWS_LEETCODE1052_H_


class Solution1052 {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res = 0;
        for(int i = 0; i<customers.size(); ++i){
            res += customers[i] * (1 - grumpy[i]);
        }

        int increase = 0;
        for(int i = 0; i<minutes; ++i){
            increase += customers[i] * grumpy[i];
        }
        int maxIncrease = increase;
        for(int i = minutes; i < customers.size(); ++i){
            increase += customers[i] * grumpy[i] - customers[i-minutes] * grumpy[i-minutes];
            maxIncrease = max(increase, maxIncrease);
        }

        return res + maxIncrease;
    }
};


void test1052(){
    Solution1052 solution1052;
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int minutes = 3;
    cout << solution1052.maxSatisfied(customers, grumpy, minutes) << endl;
    cout << solution1052.maxSatisfied(customers, grumpy, 2) << endl;
}

#endif // !_MOVE_WINDOWS_LEETCODE1052_H_