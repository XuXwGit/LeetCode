#ifndef _LEETCODE_DYNAMIC_PROGRAMMING_H
#define _LEETCODE_DYNAMIC_PROGRAMMING_H

// easy
#include "LeetCode53.h"
#include "LeetCode198.h"
#include "LeetCode213.h"

// memory search
// 1D dp
#include "LeetCode1235.h"
#include "LeetCode2008.h"
#include "LeetCode2830.h"
#include "LeetCode2054.h"
// 2D dp
#include "LeetCode10.h"
#include "LeetCode44.h"
#include "LeetCode120.h"
#include "LeetCode72.h" //same with 712 / 583
#include "LeetCode583.h"//same with 72 / 712
#include "LeetCode712.h"//same with 72 / 583
#include "LeetCode718.h" // Huawei
#include "LeetCode1143.h"
#include "LeetCode1751.h" // same as 1235

// 3D dp
#include "grid/LeetCode741.h"
#include "grid/LeetCode1463.h" // extension of 741

// sale stock problem
#include "stock/LeetCode121.h"
#include "stock/LeetCode122.h"
#include "stock/LeetCode188.h"
#include "stock/LeetCode714.h"

// network dp

// knapsack problem
#include "LeetCode377.h"

// linear dp

// state dp

// tree dp
#include "LeetCode337.h"


void test_dynamic_programming(){
    cout << " ==== test dynamic programming ==== " << endl;
    cout << " ==== sale stock problem ====" << endl;
    test121();
    test122();
    test188();
    test741();

    test1463();
    test2008();
    test2830();
    test2054();
    test1235();
    test1751();

    test10();
    test44();
    test53();
    test72();
    test120();
    test583();
    test712();
    test718();
    test1143();
    test198();
    test213();
    test377();
    test337();
    test714();
}

#endif // _LEETCODE_DYNAMIC_PROGRAMMING_H