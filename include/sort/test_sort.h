#ifndef _SORT_TEST_SORT_H_
#define _SORT_TEST_SORT_H_
#include "include_std_c++.h"

#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "leetcode_sort.h"

void test_sort(){
    cout << " ==== test sort ==== " << endl;

    test_leetcode_sort();

    srand((unsigned)time(NULL));
    int n = 20;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        nums[i] = rand() % 1000;
    }
    test_quick_sort(nums);
    test_merge_sort(nums);
    test_heap_sort(nums);
    // test_bubble_sort();
    // test_insert_sort();
    // test_select_sort();
    // test_shell_sort();
    // test_count_sort();
    // test_bucket_sort();
    cout << "Benchmark: " ;
    time_t start = clock();
    sort(nums.begin(), nums.end());
    time_t end = clock();
    cout << '\t';
    cout << "time: " << (end - start) << "ms" << endl;
    cout << '\t';
    for(auto num : nums){
        cout << num << " ";
    }
    cout << endl;
}


#endif  // _SORT_TEST_SORT_H_