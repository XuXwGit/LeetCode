#ifndef _SORT_TEST_SORT_H_
#define _SORT_TEST_SORT_H_
#include "quick_sort.h"
#include "merge_sort.h"

void test_sort(){
    vector<int> nums(20);
    for(int i = 0; i < 20; ++i){
        nums[i] = rand() % 100;
    }
    test_quick_sort(nums);
    test_merge_sort(nums);
    // test_heap_sort();
    // test_bubble_sort();
    // test_insert_sort();
    // test_select_sort();
    // test_shell_sort();
    // test_count_sort();
    // test_bucket_sort();
    cout << "Benchmark: " ;
    sort(nums.begin(), nums.end());
    for(auto num : nums){
        cout << num << " ";
    }
    cout << endl;
}


#endif  // _SORT_TEST_SORT_H_