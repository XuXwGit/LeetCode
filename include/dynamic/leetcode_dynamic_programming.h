#ifndef _LEETCODE_DYNAMIC_PROGRAMMING_H
#define _LEETCODE_DYNAMIC_PROGRAMMING_H

// easy
#include "LeetCode198.h"
#include "LeetCode213.h"

// memory search
// 1D dp
#include "LeetCode1235.h"
#include "LeetCode2008.h"
// 2D dp
#include "LeetCode10.h"
#include "LeetCode44.h"
#include "LeetCode72.h" //same with 712 / 583
#include "LeetCode583.h"//same with 72 / 712
#include "LeetCode712.h"//same with 72 / 583
#include "LeetCode1751.h" // same as 1235

// network dp

// knapsack problem
#include "LeetCode377.h"

// linear dp

// state dp

// tree dp
#include "LeetCode337.h"


void test_dynamic_programming(){
    cout << " ==== test dynamic programming ==== " << endl;
    test2008();
    test1235();
    test1751();
    test10();
    test44();
    test72();
    test583();
    test712();
    test198();
    test213();
    test377();
    test337();
}

#endif // _LEETCODE_DYNAMIC_PROGRAMMING_H