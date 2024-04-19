#ifndef _LEETCODE_76_
#define _LEETCODE_76
#include <vector>
#include <string>
#include <map>

using namespace std;


class Solution76 {
public:
    string minWindow(string s, string t) {
        map<char, int> t_map;
        for (const char& x : t) {
            t_map[x]++;
        }

        int left = 0;
        int right = 0;
        int min_len = s.size();
        string min_string = "";
        if (t_map.find(s[left]) != t_map.end()) {
            t_map[s[left]]--;
        }
        while (left <= right && right < s.size()) {
            int flag = 1;
            for (const auto& x : t_map) {
                if (x.second >0) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                if (min_len > right - left + 1) {
                    min_len = right - left + 1;
                    min_string = string(s.begin() + left, s.begin() + right + 1);
                }

                if (t_map.find(s[left]) != t_map.end()) {
                    t_map[s[left]]++;
                }
                left++;

            }
            else {
                right++;
                if (t_map.find(s[right]) != t_map.end()) {
                    t_map[s[right]]--;
                }
            }
        }

        return min_string;
    }
};

void test76() {
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaADOBECODEBANC";
    string t = "ABC";
    Solution76 solution76;
    solution76.minWindow(s, t);
}


#endif // !_LEETCODE_76_
