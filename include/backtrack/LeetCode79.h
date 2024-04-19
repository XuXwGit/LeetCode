#ifndef _LEETCODE_79_H_
#define _LEETCODE_79_H_
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution79 {
 private:
  vector<vector<char>> board;
  bool backtrack(string word, int level, int row, int col) {
    if (level == word.size() - 1 && board[row][col] == word[level]) {
      return true;
    }

    if (board[row][col] != word[level]) {
      return false;
    }

    board[row][col] -= 'A';
    if (row < board.size() - 1) {
      if (backtrack(word, level + 1, row + 1, col)) {
        return true;
      }
    }
    if (col < board[0].size() - 1) {
      if (backtrack(word, level + 1, row, col + 1)) {
        return true;
      }
    }
    if (row >= 1) {
      if (backtrack(word, level + 1, row - 1, col)) {
        return true;
      }
    }
    if (col >= 1) {
      if (backtrack(word, level + 1, row, col - 1)) {
        return true;
      }
    }
    board[row][col] += 'A';

    return false;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    this->board = board;

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        bool flag = backtrack(word, 0, i, j);
        if (flag) {
          return true;
        }
      }
    }

    return false;
  }
};

void test79() {
  Solution79 solution;
  vector<vector<char>> board = {
	{'A', 'B', 'C', 'E'},
	{'S', 'F', 'C', 'S'},
	{'A', 'D', 'E', 'E'}
  };
  cout << "Board:" << endl;
  for (auto i : board) {
      for (auto j : i) {
		cout << j << " ";
	  }
      cout << endl;
  }
  cout << "ABCCED"<< "\t" << (solution.exist(board, "ABCCED") ? "Passed" : "Failed") << endl;
  cout << "SEE"<< "\t" << (solution.exist(board, "SEE") ? "Passed" : "Failed") << endl;
  cout << "ABCB"<< "\t" << (solution.exist(board, "ABCB") ? "Passed" : "Failed") << endl;
  vector<vector<char>>  board2 = {{'a'}};
  cout << "Board:" << endl;
  for (auto i : board2) {
      for (auto j : i) {
                cout << j << " ";
      }
      cout << endl;
  }
  cout << "a"<< "\t" << (solution.exist(board2, "a") ? "Passed" : "Failed") << endl;
}   

#endif  // !_LEETCODE_79_H_
