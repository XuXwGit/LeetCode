#ifndef _LEETCODE2300_H_
#define _LEETCODE2300_H_

#include <vector>
#include <set>

class Solution2300 {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res = vector<int>(spells.size(), 0);
        sort(potions.begin(), potions.end());
        for(int i = 0; i<spells.size(); ++i){
            int left = 0;
            int right = potions.size()-1;
            int mid = right;
            long long temp = (long long)spells[i] * potions[mid];
            
            if(temp < success){
                continue;
            }
            while(left < right){
                mid = left + (right - left)/2;
                temp = (long long)spells[i] * potions[mid];
                if(temp  < success){
                    left = mid + 1;
                }else{
                    right = mid ;
                }
            }
            res[i] = potions.size() - left;
        }

        return res;
    }
};

void test2300(){
    Solution2300 solution;
    vector<int> spells = {1,2,3,4,5,6,7};
    vector<int> potions = {1,2,3,4,5,6,7};
    long long success = 7;
    vector<int> res = solution.successfulPairs(spells, potions, success);
    for(int i = 0; i<res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
}

#endif