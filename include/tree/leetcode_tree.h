#ifndef _TREE_LEETCODE_TREE_H_
#define _TREE_LEETCODE_TREE_H_


// binary tree
#include "binary_tree/LeetCode2385.h"
#include "binary_tree/LeetCode543.h"


// Trie Tree/ Prefix Tree / Dictionary Tree
//用于高效存储和查询字符串
#include "trie/LeetCode208.h"
#include "trie/LeetCode211.h"
#include "trie/LeetCode212.h"
#include "trie/LeetCode1268.h"

void test_tree(){
    // Binary Tree
    cout << "==== Binary Tree ====" << endl;
    test2385();
    test543();

    // Trie Tree
    cout << "==== Trie Tree ====" << endl;
    test208();
    test211();
    test212();
    test1268();
}


#endif // !_TREE_LEETCODE_TREE_H_