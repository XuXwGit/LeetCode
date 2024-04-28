/*
17. 电话号码的字母组合
已解答
中等

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

#ifndef _BACKTRACK_LEETCODE17_H_
#define _BACKTRACK_LEETCODE17_H_


class Solution17 {
private:
    void backtrack(string& digits, string& s, int level, vector<string>& res){
        if(level == digits.size()){
            res.push_back(s);
            return;
        }

        for(auto x: maps[digits[level]]){
            s.push_back(x);
            backtrack(digits, s, level + 1, res);
            s.pop_back();
        }
    }
    map<char, string> maps;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }

        maps['2'] = "abc";
        maps['3'] = "def";
        maps['4'] = "ghi";
        maps['5'] = "jkl";
        maps['6'] = "mno";
        maps['7'] = "pqrs";
        maps['8'] = "tuv";
        maps['9'] = "wxyz";

        vector<string> res;
        string s = "";
        backtrack(digits, s, 0, res);
        
        return res;
    }
};

void test17(){
    Solution17 solution;
    string digits = "23";
    auto res = solution.letterCombinations(digits);
    for(auto x: res){
        cout << x << " ";
    }
    cout << endl;

}

#endif // !_BACKTRACK_LEETCODE17_H_