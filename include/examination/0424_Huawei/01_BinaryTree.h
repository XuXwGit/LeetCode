/*

*/

#ifndef BINARYTREE_H
#define BINARYTREE_H


string solution(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());

    string res = "S";

    int left = 0;
    int right = nums.size()-1;
    int mid;
    while(left <= right){
        mid = (right + left)/2;
        if(nums[mid] == target){
            res += 'Y';
            break;
        }else if(nums[mid] < target){
            res += 'R';
            left = mid + 1;
        }else if(nums[mid] > target){
            res += 'L';
            right = mid - 1;
        }
    }

    if(res.back() != 'Y'){
        res.push_back('N');
    }

    return res;
}


void test_binaryTree(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    cout << solution(nums, target) << endl;

    target = 10;
    cout << solution(nums, target) << endl;
}

#endif //