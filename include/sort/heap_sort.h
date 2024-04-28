#ifndef _SORT_HEAP_SORT_H_
#define _SORT_HEAP_SORT_H_

void max_heapify(vector<int>& nums, int start, int len){
    int dad = start;
    int son = 2 * dad + 1;
    while(son < len){
        // if right child greater than left child
        if(son + 1 < len && nums[son] < nums[son + 1]){
            son = son + 1;
        }
        if(nums[dad] > nums[son]){
            return;
        }else{
            swap(nums[dad], nums[son]);
            dad = son;
            son = 2 * dad + 1;
        }
    }
}

void heap_sort(vector<int>& nums){
    int len = nums.size();
    for(int i = len/2 - 1; i >= 0; i--){
        max_heapify(nums, i, len);
    }
    for(int i = len - 1; i > 0; i--){
        swap(nums[0], nums[i]);
        max_heapify(nums, 0, i);
    }
}

void test_heap_sort(){
    vector<int> nums = {3, 2, 1, 5, 4, 7, 2, 6};
    heap_sort(nums);
    cout << "heap sort: " ;
    for(auto num : nums){
        cout << num << " ";
    }
    cout << endl;
}

void test_heap_sort(const vector<int>& temp){
    vector<int> nums = temp;
    time_t start = clock();
    heap_sort(nums);
    time_t end = clock();
    cout << "heap sort: " ;
    cout << '\t';
    cout << "time: " << (end - start) << "ms" << endl;
    cout << '\t';
    for(auto num : nums){
        cout << num << " ";
    }
    cout << endl;
}

#endif