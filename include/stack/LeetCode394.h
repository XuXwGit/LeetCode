#ifndef _LEETCODE_394_H_
#define _LEETCODE_394_H_

#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution394 {
 public:
  string decodeString(string s) {
    vector<string> sta;
    stack<int> num;

    int i = 0;
    while (i < s.size()) {
      if ('0' <= s[i] && s[i] <= '9') {
        string count = "";
        while ('0' <= s[i] && s[i] <= '9') {
          count.push_back(s[i]);
          ++i;
        }
        num.push(stoi(count));
        i++;
      } else if ('a' <= s[i] && s[i] <= 'z') {
        string tempstr;
        while ('a' <= s[i] && s[i] <= 'z') {
          tempstr.push_back(s[i]);
          ++i;
        }
        sta.push_back(tempstr);
      } else if (s[i] == ']') {
        string temp = sta.back();
        sta.pop_back();
        for (int j = 0; j < num.top(); ++j) {
          sta.back() += temp;
        }
        num.pop();
        i++;
      }
    }

    string str = "";
    for (int i = 0; i < sta.size(); ++i) {
      str += sta[i];
    }

    return str;
  }
};

void test394() {
  Solution394 solution394;
  cout << solution394.decodeString("3[a2[c]]") << endl;
  cout << solution394.decodeString("3[a]2[bc]") << endl;
  cout << solution394.decodeString("2[abc]3[cd]ef") << endl;
  cout << solution394.decodeString("abc3[cd]xyz") << endl;
  cout << solution394.decodeString("100[leetcode]") << endl;
}

#endif  // !_LEETCODE_394_H_
