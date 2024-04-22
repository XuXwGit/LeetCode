/*
208. 实现 Trie (前缀树)

Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。
请你实现 Trie 类：
Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
*/


#ifndef _TREE_LEETCODE208_H_
#define _TREE_LEETCODE208_H_


class Trie{
private:
    bool isEnd;
    vector<Trie*> children;

public:
    Trie(): isEnd(false), children(26, nullptr){}

    void insert(string word){
        Trie* node = this;
        for(auto x: word){
            if(node->children[x - 'a'] == nullptr){
                node->children[x - 'a'] = new Trie();
            }
            node = node->children[x - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word){
        Trie* node = this;
        for(auto x: word){
            if(node->children[x - 'a']==nullptr){
                return false;
            }
            node = node->children[x - 'a'];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix){
        Trie* node = this;
        for(auto x: prefix){
            if(node->children[x - 'a'] == nullptr){
                return false;
            }
            node = node->children[x - 'a'];
        }

        return true;
    }

    void remove(string word){
        Trie* node = this;
        for(auto x: word){
            if(node->children[x - 'a'] == nullptr){
                return;
            }
            node = node->children[x - 'a'];
        }
        node->isEnd = false;
    }
};


void test208(){
    Trie* obj = new Trie();
    obj->insert("apple");
    cout<<obj->search("apple")<<endl;
    cout<<obj->search("app")<<endl;
    cout<<obj->startsWith("app")<<endl;
    obj->insert("app");
    cout<<obj->search("app")<<endl;
    obj->remove("app");
    cout<<obj->search("app")<<endl;
}


#endif // !_TREE_LEETCODE208_H_