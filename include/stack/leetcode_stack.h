#ifndef _LEETCODE_STACK_H_
#define _LEETCODE_STACK_H_

// monotonic stack
#include "monotonic_stack/LeetCode42.h"
#include "monotonic_stack/LeetCode1475.h"
#include "monotonic_stack/LeetCode84.h"

#include "LeetCode394.h"

void test_stack(){
    cout << " ==== test stack ==== " << endl;
    cout << " ==== monotonic stack ==== " << endl;
    test42();
    test1475();
    test84();
    test394();
}

#endif // !_LEETCODE_STACK_H_