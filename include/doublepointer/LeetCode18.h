/*
18. 四数之和

给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。
*/


#ifndef _DOUBLE_POINTER_LEETCODE18_H_
#define _DOUBLE_POINTER_LEETCODE18_H_

class Solution18 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<int, vector<pair<int,int>>> twoSums;
        for(int i = 0; i<nums.size()-1; ++i){
            for(int j = i+1; j<nums.size(); ++j){
                twoSums[nums[i] + nums[j]].emplace_back(i,j);
            }
        }
        vector<int> twoSumValues;
        for(auto x: twoSums){
            twoSumValues.push_back(x.first);
        }

        sort(twoSumValues.begin(), twoSumValues.end());

        vector<vector<int>> res;
        int left = 0;
        int right = twoSumValues.size()-1;
        while(left < right){
            if(twoSumValues[left] + twoSumValues[right] > target){
                right --;
            }else if(twoSumValues[left] + twoSumValues[right] < target){
                left ++;
            }else{
                for(auto x: twoSums[twoSumValues[left]]){
                    for(auto y: twoSums[twoSumValues[right]]){
                        int a = x.first;
                        int b = x.second;
                        int c = y.first;
                        int d = y.second;
                        if(a == c || a == d || b == c || b == d){
                            left ++;
                            right --;
                        }else{
                            vector<int> temp = {nums[a], nums[b], nums[c], nums[d]};
                            sort(temp.begin(), temp.end());
                            res.push_back(temp);
                            left ++;
                            right --;
                        }
                    }
                }
            }
        }

        return res;
    }
};

void test18(){
    Solution18 s;
    // nums = [1,0,-1,0,-2,2], target = 0
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> res = s.fourSum(nums, target);
    for(auto x: res){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }
}

#endif // !_DOUBLE_POINTER_LEETCODE18_H_