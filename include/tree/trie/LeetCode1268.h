/*
1268. 搜索推荐系统
中等

给你一个产品数组 products 和一个字符串 searchWord ，products  数组中每个产品都是一个字符串。

请你设计一个推荐系统，在依次输入单词 searchWord 的每一个字母后，推荐 products 数组中前缀与 searchWord 相同的最多三个产品。如果前缀相同的可推荐产品超过三个，请按字典序返回最小的三个。

请你以二维列表的形式，返回在输入 searchWord 每个字母后相应的推荐产品的列表。
*/


#ifndef _TREE_TRIE_LEETCODE1268_H_
#define _TREE_TRIE_LEETCODE1268_H_


class Solution1268 {
private:
    struct TrieNode{
        map<char, TrieNode*> children;
        priority_queue<string> pq;
    }* root;

    void insert(const string& product){
        TrieNode* node = root;
        for(auto x: product){
            if(!node->children.count(x)){
                node->children[x] = new TrieNode();
            }
            node = node->children[x];
            node->pq.push(product);
            if(node->pq.size()>3){
                node->pq.pop();
            }
        }
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode();
        for(auto x: products){
            insert(x);
        }

        vector<vector<string>> result(searchWord.size());
        TrieNode* node = root;
        for(int i = 0; i<searchWord.size(); ++i){
            vector<string> temp;
            if(!node->children.count(searchWord[i])){
                break;
            }else{
                node = node->children[searchWord[i]];
                priority_queue<string> temp_pq = node->pq;
                while(!temp_pq.empty()){
                    temp.push_back(temp_pq.top());
                    temp_pq.pop();
                }
                reverse(temp.begin(), temp.end());
            }
            result[i] = temp;
        }

        return result;
    }
};





void test1268(){
    cout<<"Test LeetCode1268: "<<endl;
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord = "mouse";
    Solution1268 s;
    vector<vector<string>> result = s.suggestedProducts(products, searchWord);
    for(auto x: result){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}

#endif // !_TREE_TRIE_LEETCODE1268_H_