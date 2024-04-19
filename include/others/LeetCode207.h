#ifndef _LEETCODE_207_
#define _LEETCODE_207_

#include <vector>
using namespace std;

class Solution207 {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> back_nodes(numCourses);
    vector<int> num_pre(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); ++i) {
      back_nodes[prerequisites[i][1]].push_back(prerequisites[i][0]);
      num_pre[prerequisites[i][0]]++;
    }

    for (int i = 0; i < num_pre.size(); ++i) {
      if (num_pre[i] == 0) {
        for (int j = 0; j < back_nodes[i].size(); ++j) {
          num_pre[back_nodes[i][j]]--;
        }
      }
    }

    for (int i = 0; i < num_pre.size(); ++i) {
      if (num_pre[i] > 0) {
        return false;
      }
    }

    return true;
  }
};

void test207() { Solution207 solution;
  int numCourses = 5; 
  vector<vector< int >> prerequisites = {{1, 4}, {2, 4}, {3, 1}, {3, 2}};
  solution.canFinish(numCourses, prerequisites);
}

#endif  // !_LEETCODE_207_
