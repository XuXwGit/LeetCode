/*
1233. 删除子文件夹
已解答
中等
相关标签
相关企业
提示
你是一位系统管理员，手里有一份文件夹列表 folder，你的任务是要删除该列表中的所有 子文件夹，并以 任意顺序 返回剩下的文件夹。

如果文件夹 folder[i] 位于另一个文件夹 folder[j] 下，那么 folder[i] 就是 folder[j] 的 子文件夹 。

文件夹的「路径」是由一个或多个按以下格式串联形成的字符串：'/' 后跟一个或者多个小写英文字母。

例如，"/leetcode" 和 "/leetcode/problems" 都是有效的路径，而空字符串和 "/" 不是。


示例 1：

输入：folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
输出：["/a","/c/d","/c/f"]
解释："/a/b" 是 "/a" 的子文件夹，而 "/c/d/e" 是 "/c/d" 的子文件夹。
示例 2：

输入：folder = ["/a","/a/b/c","/a/b/d"]
输出：["/a"]
解释：文件夹 "/a/b/c" 和 "/a/b/d" 都会被删除，因为它们都是 "/a" 的子文件夹。
示例 3：

输入: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
输出: ["/a/b/c","/a/b/ca","/a/b/d"]


提示：

1 <= folder.length <= 4 * 10^4
2 <= folder[i].length <= 100
folder[i] 只包含小写字母和 '/'
folder[i] 总是以字符 '/' 起始
folder 每个元素都是 唯一 的
*/

#ifndef _LEETCODE_TREE_TRIE_LEETCODE1233_H_
#define _LEETCODE_TREE_TRIE_LEETCODE1233_H_

class Solution1233
{
private:
    struct TrieNode
    {
        bool isEnd;
        vector<TrieNode *> children;
        TrieNode() : isEnd(false), children(vector<TrieNode *>(27, nullptr)) {}
    };
    TrieNode *root;
    void insert(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (ch == '/')
            {
                if (node->children[26] == nullptr)
                {
                    node->children[26] = new TrieNode();
                }
                node = node->children[26];
            }
            else
            {
                if (node->children[ch - 'a'] == nullptr)
                {
                    node->children[ch - 'a'] = new TrieNode();
                }
                node = node->children[ch - 'a'];
            }
        }
        node->isEnd = true;
    }
    void dfs(TrieNode *node, string sol, vector<string> &res)
    {
        if (node->isEnd)
        {
            res.push_back(sol);
            for (int i = 0; i < 26; ++i)
            {
                if (node->children[i] != nullptr)
                {
                    sol.push_back((char)('a' + i));
                    dfs(node->children[i], sol, res);
                    sol.pop_back();
                }
            }
            return;
        }

        for (int i = 0; i < 26; ++i)
        {
            if (node->children[i] != nullptr)
            {
                sol.push_back((char)('a' + i));
                dfs(node->children[i], sol, res);
                sol.pop_back();
            }
        }
        if (node->children[26] != nullptr)
        {
            sol.push_back('/');
            dfs(node->children[26], sol, res);
            sol.pop_back();
        }
    }

public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        root = new TrieNode();

        for (string word : folder)
        {
            insert(word);
        }

        vector<string> res;
        string sol = "";
        dfs(root, sol, res);

        return res;
    }
};

void test1233()
{
    Solution1233 solution1233;
    vector<string> folder = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    vector<string> res = solution1233.removeSubfolders(folder);
    for (string str : res)
    {
        cout << str << endl;
    }
}

#endif // !_LEETCODE_TREE_TRIE_LEETCODE1233_H_