#ifndef LEETCODE_GREEDY_H
#define LEETCODE_GREEDY_H

#include "include_std_c++.h"
#include "LeetCode0510.h"
#include "LeetCode826.h"
#include "LeetCode857.h"
#include "LeetCode1953.h"

// range problems
#include "ranges/LeetCode56.h"
#include "ranges/LeetCode435.h"
#include "ranges/LeetCode452.h"
#include "ranges/LeetCode763.h"

void test_greedy(){
    cout << "==== test greedy ====" << endl;
    test0510();
    test826();
    test857();
    test1953();

    // range problems
    test56();
    test435();
    test452();
    test763();
}

#endif