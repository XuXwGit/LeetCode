/*
211. 添加与搜索单词 - 数据结构设计
请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。
实现词典类 WordDictionary ：
WordDictionary() 初始化词典对象
void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。
*/

#ifndef _TREE_LEETCODE211_H_
#define _TREE_LEETCODE211_H_

#include "include_std_c++.h"

class WordDictionary {
private:
    struct Node {
        bool isEnd;
        vector<Node*> children;
        Node() : isEnd(false), children(26, nullptr) {}
    };
    Node* root;

public:
    WordDictionary() : root(new Node()) {}

    void addWord(string word) {
        Node* node = root;
        for (auto x : word) {
            if (node->children[x - 'a'] == nullptr) {
                node->children[x - 'a'] = new Node();
            }
            node = node->children[x - 'a'];
        }
        node->isEnd = true;
    }

    bool search_aux(Node* root, string word, int index) {
        if(root == nullptr){
            return false;
        }
        
        if (index == word.size()) {
            return root->isEnd;
        }

        if (word[index] == '.') {
            bool res = false;
            for (int j = 0; j < 26; ++j) {
                res = res || search_aux(root->children[j], word, index + 1);
                if (res) {
                    return res;
                }
            }
            return res;
        }else{
            if (root->children[word[index] - 'a'] == nullptr) {
                return false;
            }else{
                return search_aux(root->children[word[index] - 'a'], word, index+1);
            }            
        }
    }

    bool search(string word) { return search_aux(root, word, 0); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

void test211(){
    // ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
    // [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
    // [null,null,null,null,false,true,true,true]
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    cout<<obj->search("pad")<<endl;
    cout<<obj->search("bad")<<endl;
    cout<<obj->search(".ad")<<endl;
    cout<<obj->search("b..")<<endl;
}


#endif // !_TREE_LEETCODE211_H_