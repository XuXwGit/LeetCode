/*
2709. 最大公约数遍历
困难

给你一个下标从 0 开始的整数数组 nums ，你可以在一些下标之间遍历。对于两个下标 i 和 j（i != j），当且仅当 gcd(nums[i], nums[j]) > 1 时，我们可以在两个下标之间通行，其中 gcd 是两个数的 最大公约数 。

你需要判断 nums 数组中 任意 两个满足 i < j 的下标 i 和 j ，是否存在若干次通行可以从 i 遍历到 j 。

如果任意满足条件的下标对都可以遍历，那么返回 true ，否则返回 false 。
*/

#ifndef _LEETCODE_MATH_LEETCODE_2709_H_
#define _LEETCODE_MATH_LEETCODE_2709_H_

#include "include_std_c++.h"

class Solution2709 {
private:
    unordered_map<int, int> parent;
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void connect(int x, int y){
        int p_x = find(x);
        int p_y = find(y);
        if(p_x != p_y){
            parent[p_x] = p_y;
        }
    }
    bool isConnected(int x, int y){
        return find(x) == find(y);
    }
public:
    bool canTraverseAllPairs(vector<int>& nums){
        for(int i = 0; i<nums.size(); ++i){
            cout << nums[i] << endl;
        }

        for(int i = 0; i<nums.size(); ++i){
            for(int j = 2; j <= nums[i]/j; ++j){
                if(nums[i]%j == 0){
                    connect(i, j);
                    printf("i=%d, j=%d\n", i, j);
                    while(nums[i]%j == 0){
                        nums[i] /= j;
                    }
                }
            }

            if(nums[i] > 1){
                connect(i, nums[i]);
                printf("i=%d, j=%d\n", i, nums[i]);
            }
        }

        for(int i = 0; i<nums.size(); ++i){
            for(int j = i+1; j < nums.size(); ++j){
                cout << "i=" << i << ", j=" << j  << "isConnected=" << isConnected(i, j) << endl;
                if(!isConnected(i, j)){
                    return false;
                }
            }
        }

        return true;
    }
};


void test2709(){
    // [3,9,5]
    Solution2709 solution;
    vector<int> nums = {3, 9, 5};
    cout << (solution.canTraverseAllPairs(nums) ? "true" : "false") << endl;
    // [2,6,7,4]
    nums = {2, 6, 7, 4};
    cout << (solution.canTraverseAllPairs(nums) ? "true" : "false") << endl;
}


#endif // !_LEETCODE_MATH_LEETCODE_2709_H_