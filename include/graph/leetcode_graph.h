#ifndef _LEETCODE_GRAPH_H_
#define _LEETCODE_GRAPH_H_

#include "include_std_c++.h"

// DFS
#include "dfs/LeetCode200.h"
#include "dfs/LeetCode797.h"
#include "dfs/LeetCode841.h"
#include "dfs/LeetCode924.h"
#include "dfs/LeetCode928.h"
#include "dfs/LeetCode994.h"
#include "dfs/LeetCode1971.h"
#include "dfs/LeetCode2192.h"

// BFS
#include "bfs/LeetCode924.h"
#include "bfs/LeetCode2101.h"

// Topological Sort
#include "topological/LeetCode207.h"
#include "topological/LeetCode210.h"
#include "topological/LeetCode1203.h"
#include "topological/LeetCode1462.h"
#include "topological/LeetCode2115.h"

// Union Find
#include "union_find/LeetCode128.h"
#include "union_find/LeetCode130.h"
#include "union_find/LeetCode547.h"
#include "union_find/LeetCode684.h"
#include "union_find/LeetCode685.h"
#include "union_find/LeetCode924.h"
#include "union_find/LeetCode2316.h"
#include "union_find/LeetCode2685.h"

// Shortest Path Problem : Dijkstra V\S Floyd
// Dijkstra can only handle "positive weight" edges and "single source" shortest path
// Floyd can handle "negative weight" edges and "all pairs" shortest path
// Shortest Path (Dijkstra)
#include "dijkstra/LeetCode743.h"
#include "dijkstra/LeetCode1514.h"
#include "dijkstra/LeetCode1631.h"
#include "dijkstra/LeetCode1786.h"
#include "dijkstra/LeetCode2642.h"
#include "dijkstra/LeetCode3112.h"

// Shortest Path (Floyd)
#include "floyd/LeetCode1334.h"
#include "floyd/LeetCode2976.h"
#include "floyd/LeetCode399.h"
#include "floyd/LeetCode2642Floyd.h"

// Pseudotree
#include "pseudotree/LeetCode2127.h"
#include "pseudotree/LeetCode2360.h"
#include "pseudotree/LeetCode2876.h"

// Minimum Spanning Tree
#include "spanningtree/LeetCode1489.h"
#include "spanningtree/LeetCode1584.h"

// Maximum Flow

// Bipartite Matching
#include "bipartite/LeetCode785.h"

void test_graph(){
    cout << " ==== test graph ==== " << endl;
    cout << " ==== floyd ==== " << endl;
    // floyd
    test2642Floyd();
    test1334();
    test2976();
    test399();

    cout << " ==== dijkstra ==== " << endl;
    // dijkstra
    test743();
    test1514();
    test1631();
    test1786();
    test2642();
    test3112();

    cout << " ==== union find ==== " << endl;
    // union find
    test128();
    test130();
    test547();
    test684();
    test685();
    test924UFS();
    test2316();
    test2685();

    cout << " ==== dfs ==== " << endl;
    // dfs
    test200();
    test130();
	test928();
	test924();
    test994();
    test1971();
    test2192();

    cout << " ==== bfs ==== " << endl;
    test924BFS();
    test2101();

    cout << " ==== topological sort ==== " << endl;
    test207();
    test210();
    test1203();
    test1462();
    test2115();

    cout << " ==== pseudotree ==== " << endl;
    test2127();
}


#endif // !_LEETCODE_GRAPH_H_