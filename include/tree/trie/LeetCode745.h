/*
745. 前缀和后缀搜索
困难
相关标签
相关企业
提示
设计一个包含一些单词的特殊词典，并能够通过前缀和后缀来检索单词。

实现 WordFilter 类：

WordFilter(string[] words) 使用词典中的单词 words 初始化对象。
f(string pref, string suff) 返回词典中具有前缀 pref 和后缀 suff 的单词的下标。如果存在不止一个满足要求的下标，返回其中 最大的下标 。如果不存在这样的单词，返回 -1 。


示例：

输入
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
输出
[null, 0]
解释
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // 返回 0 ，因为下标为 0 的单词：前缀 prefix = "a" 且 后缀 suffix = "e" 。

提示：

1 <= words.length <= 104
1 <= words[i].length <= 7
1 <= pref.length, suff.length <= 7
words[i]、pref 和 suff 仅由小写英文字母组成
最多对函数 f 执行 104 次调用
*/

#ifndef _LEETCODE_TREE_TRIE_LEETCODE745_H_
#define _LEETCODE_TREE_TRIE_LEETCODE745_H_

class WordFilter
{
private:
    struct TrieNode
    {
        bool isEnd;
        vector<int> indexs;
        vector<TrieNode *> children;
        TrieNode() : isEnd(false), children(vector<TrieNode *>(26, nullptr)) {}
    };
    TrieNode *head;
    TrieNode *tail;

    void insert(string word, int index)
    {
        TrieNode *node = head;
        for (char ch : word)
        {
            if (node->children[ch - 'a'] == nullptr)
            {
                node->children[ch - 'a'] = new TrieNode();
            }
            node->children[ch - 'a']->indexs.push_back(index);
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;

        node = tail;
        reverse(word.begin(), word.end());
        for (char ch : word)
        {
            if (node->children[ch - 'a'] == nullptr)
            {
                node->children[ch - 'a'] = new TrieNode();
            }
            node->children[ch - 'a']->indexs.push_back(index);
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
    }

    vector<int> queryPrefix(string word)
    {
        TrieNode *node = head;
        for (char ch : word)
        {
            if (node->children[ch - 'a'] == nullptr)
            {
                return vector<int>{};
            }
            node = node->children[ch - 'a'];
        }
        return node->indexs;
    }

    vector<int> querySuffix(string word)
    {
        reverse(word.begin(), word.end());
        TrieNode *node = tail;
        for (char ch : word)
        {
            if (node->children[ch - 'a'] == nullptr)
            {
                return vector<int>{};
            }
            node = node->children[ch - 'a'];
        }
        return node->indexs;
    }

public:
    WordFilter(vector<string> &words)
    {
        head = new TrieNode();
        tail = new TrieNode();
        for (int i = 0; i < words.size(); ++i)
        {
            insert(words[i], i);
        }
    }

    int f(string pref, string suff)
    {
        vector<int> index1 = queryPrefix(pref);
        vector<int> index2 = querySuffix(suff);
        if (index1.empty() || index2.empty())
        {
            return -1;
        }
        reverse(index1.begin(), index1.end());
        reverse(index2.begin(), index2.end());
        int l1 = 0, l2 = 0;
        while (l1 < index1.size() && l2 < index2.size())
        {
            if (index1[l1] == index2[l2])
            {
                return index1[l1];
            }
            else if (index1[l1] < index1[l2])
            {
                l1++;
            }
            else
            {
                l2++;
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */

void test745()
{
    vector<string> words = {"apple"};
    WordFilter wordFilter(words);
    cout << wordFilter.f("a", "e") << endl;
}

#endif // !_LEETCODE_TREE_TRIE_LEETCODE745_H_