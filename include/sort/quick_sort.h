#ifndef _SORT_QUICK_SORT_H_
#define _SORT_QUICK_SORT_H_

#include <vector>
#include <iostream>

using namespace std;

template<typename T = int>
void quick_sort(vector<T>& nums, int left, int right){
    if(left >= right){
        return;
    }

    int base = nums[left + right >> 1];

    int i = left, j = right;
    while(i < j){
        while(nums[i] < base){
            i++;
        }
        while(nums[j] > base){
            j--;
        }
        if(i < j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    quick_sort(nums, left, i - 1);
    quick_sort(nums, j + 1, right);
}

template<typename T = int>
void quick_sort(vector<T>& nums){
    quick_sort(nums, 0, nums.size() - 1);
}

void test_quick_sort(){
    vector<int> nums = {3, 2, 1, 5, 4, 7, 2, 6};
    quick_sort(nums);
    cout << "quick sort: " ;
    for(auto num : nums){
        cout << num << " ";
    }
    cout << endl;
}

template<typename T = int>
void test_quick_sort(const vector<T>& temp){
    vector<T> nums = temp;
    time_t start = clock();
    quick_sort(nums);
    time_t end = clock();
    cout << "quick sort: " ;
    cout << '\t';
    cout << "time: " << (end - start) << "ms" << endl;
    cout << '\t';
    for(auto num : nums){
        cout << num << " ";
    }

    cout << endl;
}


#endif  // _SORT_QUICK_SORT_H_