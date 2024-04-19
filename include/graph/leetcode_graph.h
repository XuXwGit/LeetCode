#ifndef _LEETCODE_GRAPH_H_
#define _LEETCODE_GRAPH_H_

// DFS
#include "dfs/LeetCode200.h"
#include "dfs/LeetCode944.h"
#include "dfs/LeetCode1971.h"
#include "dfs/LeetCode928.h"
#include "dfs/LeetCode924.h"

// BFS

// Topological Sort

// Shortest Path Problem : Dijkstra V\S Floyd
// Dijkstra can only handle "positive weight" edges and "single source" shortest path
// Floyd can handle "negative weight" edges and "all pairs" shortest path
// Shortest Path (Dijkstra)
#include "dijkstra/LeetCode743.h"
#include "dijkstra/LeetCode2642.h"
#include "dijkstra/LeetCode1514.h"
#include "dijkstra/LeetCode1631.h"

// Shortest Path (Floyd)
#include "floyd/LeetCode1334.h"
#include "floyd/LeetCode2976.h"

// Minimum Spanning Tree 

// Maximum Flow

// Bipartite Matching


void test_graph(){
    // floyd
    test1334();
    test2976();

    // dijkstra
    test1631();
    test743();


	test928();
	test924();
    test944();
    test1971();
    test200();
}


#endif // !_LEETCODE_GRAPH_H_