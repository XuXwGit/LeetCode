/*
212. 单词搜索 II

给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words， 返回所有二维网格上的单词 。
单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
*/

#ifndef _TREE_LEETCODE212_H_
#define _TREE_LEETCODE212_H_

#include "include_std_c++.h"


/*
* DFS
* The following solution error in large test cases.
class Solution {
private:
    bool dfs(int row, int col, string word, vector<vector<char>>& board, vector<vector<bool>>& isvisited, int index){
        if(index == word.size())    return true;
        if(word[index] != board[row][col])  return false;
        if(index == word.size()-1)  return true;

        isvisited[row][col] = true;

        bool flag = false;

        if(row > 0 && !isvisited[row-1][col]){
            flag = flag || dfs(row - 1, col, word, board, isvisited, index+1);
            if(flag){
                return true;
            }
        }
        
        if(col > 0 && !isvisited[row][col-1]){
            flag = flag || dfs(row, col - 1, word, board, isvisited, index+1);
            if(flag){
                return true;
            }
        }

        if(row < board.size()-1 && !isvisited[row+1][col]){
            flag = flag || dfs(row+1, col, word, board, isvisited, index+1);
            if(flag){
                return true;
            }
        }

        if(col < board[0].size()-1 && !isvisited[row][col+1]){
            flag = flag || dfs(row, col+1, word, board, isvisited, index+1);
            if(flag){
                return true;
            }
        }

        isvisited[row][col] = false;

        return flag;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        map<char, vector<pair<int, int>>> pos;
        for(int i = 0; i<board.size(); ++i){
            for(int j = 0; j<board[0].size(); ++j){
                pos[board[i][j]].emplace_back(i, j);
            }
        }

        vector<string> res;
        
        for(string word: words){
            for(auto [x, y]: pos[word[0]]){
                vector<vector<bool>> isvisited(board.size(), vector<bool>(board[0].size(), false));
                if(dfs(x, y, word, board, isvisited, 0)){
                    res.push_back(word);
                    break;
                }
            }
        }

        return res;
    }
};
*/

// use Trie can only DFS search once
class Solution {
private:
    struct TrieNode{
        int id;
        vector<TrieNode*> children;
        // children need to be initial as nullptr , otherwise will increase dfs
        TrieNode():id(-1), children(26, nullptr){}
    };
    
    TrieNode* root;
    vector<vector<char>> board;

    void insert(const string& word, int id){
        TrieNode* node = root;
        for(auto x: word){
            if(node->children[x-'a'] == nullptr){
                node->children[x-'a'] = new TrieNode();
            }
            node = node->children[x-'a'];
        }
        node->id = id;
    }

    // int search(const string& word){
    //     TrieNode* node = root;
    //     for(auto x: word){
    //         if(node->children[x-'a'] == nullptr){
    //             return -1;
    //         }
    //         node = node->children[x-'a'];
    //     }
    //     return node->id;
    // }

    void dfs(int row, int col, TrieNode* root){
        if(root->id>=0){
            record.insert(root->id);
            root->id = -1;
        }

        char ch = board[row][col];
        board[row][col] = '#';

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int i = 0; i<4; ++i)
        {
            int x = row + dx[i];
            int y = col + dy[i];

            if(x >= 0 && x<board.size() && y >= 0 && y<board[0].size() && board[x][y]!='#'){
                if(root->children[board[x][y]-'a'])
                    dfs(x, y, root->children[board[x][y]-'a']);
            }
        }

        board[row][col] = ch;
    }
    set<int> record;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        this->board = board;

        for(int i = 0; i<words.size(); ++i){
            insert(words[i], i);
        }

        for(int i = 0; i<board.size(); ++i){
            for(int j = 0; j<board[0].size(); ++j){
                if(root->children[board[i][j]-'a'])
                    dfs(i, j, root->children[board[i][j]-'a']);
            }
        }

        vector<string> res;
        for(auto x: record){
            res.emplace_back(words[x]);
        }

        return res;
    }
};



void test212(){
    cout << "======= test212 =======" << endl;
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    Solution s;
    s.findWords(board, words);


    // board = [["a","b","c"],["a","e","d"],["a","f","g"]]
    // words = ["eaafgdcba","eaabcdgfa"]
    // Output: ["eaabcdgfa","gfedcbaaa"]
    board = {
        {'a','b','c'},
        {'a','e','d'},
        {'a','f','g'}
    };
    words = {"eaafgdcba","eaabcdgfa"};
    s.findWords(board, words);


    cout << "======= end =======" << endl;

}


#endif