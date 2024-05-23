#ifndef _LEETCODE_GRAPH_H_
#define _LEETCODE_GRAPH_H_

// DFS
#include "dfs/LeetCode200.h"
#include "dfs/LeetCode994.h"
#include "dfs/LeetCode1971.h"
#include "dfs/LeetCode928.h"
#include "dfs/LeetCode924.h"

// BFS
#include "bfs/LeetCode207.h"

// Union Find
#include "union_find/LeetCode128.h"
#include "union_find/LeetCode130.h"
#include "union_find/LeetCode684.h"
#include "union_find/LeetCode685.h"

// BFS

// Topological Sort
#include "bfs/LeetCode207.h"
#include "bfs/LeetCode210.h"

// Shortest Path Problem : Dijkstra V\S Floyd
// Dijkstra can only handle "positive weight" edges and "single source" shortest path
// Floyd can handle "negative weight" edges and "all pairs" shortest path
// Shortest Path (Dijkstra)
#include "dijkstra/LeetCode743.h"
#include "dijkstra/LeetCode2642.h"
#include "dijkstra/LeetCode1514.h"
#include "dijkstra/LeetCode1631.h"
#include "dijkstra/LeetCode3112.h"

// Shortest Path (Floyd)
#include "floyd/LeetCode1334.h"
#include "floyd/LeetCode2976.h"
#include "floyd/LeetCode399.h"

// Minimum Spanning Tree 

// Maximum Flow

// Bipartite Matching


void test_graph(){
    cout << " ==== test graph ==== " << endl;
    cout << " ==== floyd ==== " << endl;
    // floyd
    test1334();
    test2976();
    test399();

    cout << " ==== dijkstra ==== " << endl;
    // dijkstra
    test1631();
    test743();
    test2642();
    test1514();
    test3112();

    cout << " ==== union find ==== " << endl;
    // union find
    test128();
    test130();
    test684();
    test685();

    cout << " ==== dfs ==== " << endl;
    // dfs
    test130();
	test928();
	test924();
    test994();
    test1971();
    test200();

    cout << " ==== bfs ==== " << endl;
    cout << " ==== topological sort ==== " << endl;
    test207();
    test210();
}


#endif // !_LEETCODE_GRAPH_H_