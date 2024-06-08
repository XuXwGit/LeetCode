#ifndef LEETCODE_MATH_H
#define LEETCODE_MATH_H

#include "include_std_c++.h"

// The principle of inclusion-exclusion
#include "inclusion-exclusion/LeetCode2928.h"

#include "LeetCode204.h"
#include "LeetCode1016.h"
#include "LeetCode1017.h"
#include "LeetCode2521.h"
#include "LeetCode1979.h"
#include "LeetCode2709.h"

void test_math(){
    cout << " ==== test math ==== " << endl;
    cout << " ==== inclusion-exclusion principle ==== " << endl;
    test2928();

    test204();
    test1016();
    test1017();
    test1979();
    test2521();
    test2709();
}

#endif