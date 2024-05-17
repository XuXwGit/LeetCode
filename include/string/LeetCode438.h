#ifndef _LEETCODE_438_
#define _LEETCODE_438_

#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution438 {
public:
    vector<int> findAnagrams_I(string s, string p) {
        vector<int> res;

        map<char, int> p_map;
        for (const char& x : p) {
            if (p_map.find(x) == p_map.end()) {
                p_map.insert(pair<char, int>(x, 1));
            }
            else {
                p_map[x]++;
            }
        }

        int left = 0;
        while (left <= static_cast<int>(s.size()) - static_cast<int>(p.size())) {
            map<char, int> temp_map = p_map;
            for (int i = left; i < left + p.size(); ++i) {
                if (temp_map.find(s[i]) == temp_map.end()) {
                    left = i;
                    break;
                }
                else {
                    temp_map[s[i]]--;
                }
            }
            int flag = 1;
            for (const auto& x : temp_map) {
                if (x.second != 0) {
                    flag = 0;
                }
            }
            if (flag) {
                res.push_back(left);
            }
            left++;
        }

        return res;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        vector<int> s_count(26, 0);
        vector<int> p_count(26, 0);

        if (s.size() < p.size())
            return res;

        for (int i = 0; i < p.size(); ++i) {
            p_count[p[i] - 'a']++;
            s_count[s[i] - 'a']++;
        }

        for (int i = 0; i < s.size() - p.size(); ++i) {
            if (s_count == p_count) {
                res.push_back(i);
            }
            s_count[s[i] - 'a']--;
            s_count[s[i + p.size()] - 'a']++;
        }
        if (s_count == p_count) {
            res.push_back(s.size() - p.size());
        }

        return res;
    }
};


void test438() {
    Solution438 sol;

    string s = "cbaebabacd";
    string p = "abc";
    vector<int> res = sol.findAnagrams(s, p);
    for (const int& x : res) {
        cout << x << " ";
    }
    cout << endl;
}

#endif // !_LEETCODE_438_