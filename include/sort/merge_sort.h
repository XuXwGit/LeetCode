#ifndef _SORT_MERGE_SORT_H_
#define _SORT_MERGE_SORT_H_


template<typename T = int>
void merge(std::vector<T>& nums, int left, int right){
    if(left >= right){
        return;
    }
    
    int mid = left + right >> 1;
    merge(nums, left, mid);
    merge(nums, mid + 1, right);

    std::vector<T> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right){
        temp[k++] = nums[i] < nums[j] ? nums[i ++] : nums[j ++];
    }
    while(i <= mid){
        temp[k++] = nums[i++];
    }
    while(j <= right){
        temp[k++] = nums[j++];
    }
    for(int i = left, k = 0; i <= right; ++i, ++k){
        nums[i] = temp[k];
    }
}

template<typename T = int>
void merge_sort(std::vector<T>& nums){
    merge(nums, 0, nums.size() - 1);
}


void test_merge_sort(){
    vector<int> nums = {3, 2, 1, 5, 4, 7, 2, 6};
    merge_sort(nums);
    cout << "merge sort: " ;
    for(auto num : nums){
        cout << num << " ";
    }
    cout << endl;
}

template<typename T = int>
void test_merge_sort(const vector<T>& temp){
    vector<T> nums = temp;
    merge_sort(nums);
    cout << "merge sort: " ;
    for(auto num : nums){
        cout << num << " ";
    }
    cout << endl;
}


#endif  // _SORT_MERGE_SORT_H_