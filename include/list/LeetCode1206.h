/*
1206. 设计跳表
困难
相关标签
相关企业
不使用任何库函数，设计一个 跳表 。

跳表 是在 O(log(n)) 时间内完成增加、删除、搜索操作的数据结构。跳表相比于树堆与红黑树，其功能与性能相当，并且跳表的代码长度相较下更短，其设计思想与链表相似。

例如，一个跳表包含 [30, 40, 50, 60, 70, 90] ，然后增加 80、45 到跳表中，以下图的方式操作：

跳表中有很多层，每一层是一个短的链表。在第一层的作用下，增加、删除和搜索操作的时间复杂度不超过 O(n)。跳表的每一个操作的平均时间复杂度是 O(log(n))，空间复杂度是 O(n)。

了解更多 : https://oi-wiki.org/ds/skiplist/

在本题中，你的设计应该要包含这些函数：

bool search(int target) : 返回target是否存在于跳表中。
void add(int num): 插入一个元素到跳表。
bool erase(int num): 在跳表中删除一个值，如果 num 不存在，直接返回false. 如果存在多个 num ，删除其中任意一个即可。
注意，跳表中可能存在多个相同的值，你的代码需要处理这种情况。
*/


#ifndef _LIST_LEETCODE1206_H_
#define _LIST_LEETCODE1206_H_

const int SKIPLIST_MAX_LEVEL = 32;
const double SKIPLIST_PROB = 0.25;

class Skiplist {
private:
    struct skiplistNode{
        int key;
        // int value;
        skiplistNode* backward;
        vector<skiplistNode* > forwards;

        // construct function
        skiplistNode(int key, int level)
            :key(key), 
            backward(nullptr), 
            forwards(vector<skiplistNode*>(level)){}
    };

    int randomLevel(){
        int level = 1;

        while(level < SKIPLIST_MAX_LEVEL 
                && std::rand()/(RAND_MAX + 1u) < SKIPLIST_PROB){
            level ++;
        }
        
        return level;
    }

    struct skiplistNode* head;
    struct skiplistNode* tail;
    long long length;
    int level;
public:
    Skiplist()
        :head(new skiplistNode(0, SKIPLIST_MAX_LEVEL)), 
            tail(nullptr), 
            length(0),
            level(1){
        for(int i = 0; i<SKIPLIST_MAX_LEVEL; ++i){
            head->forwards[i] = nullptr;
        }
    }
    
    bool search(int target) {
        struct skiplistNode* x = head;

        for(int l = level-1; l >= 0; l--){
            // x->key < target
            while(x->forwards[l] != nullptr 
                    && x->forwards[l]->key < target){
                x = x->forwards[l];
            }            
        }
        
        return x->forwards[0] && x->forwards[0]->key == target;
    }
    
    void add(int num) {
        int new_l = randomLevel();
        struct skiplistNode* new_node = new skiplistNode(num, new_l);

        struct skiplistNode* x = head;
        for(int l = level-1; l >= 0; l--){
            // x->key < target
            while(x->forwards[l] != nullptr 
                    && x->forwards[l]->key < num){
                x = x->forwards[l];
            }
            new_node->forwards[l] = x->forwards[l];
            x->forwards[l] = new_node;
        }
        if(new_l > level){
            for(int l = level; l < new_l; ++l){
                head->forwards[l] = new_node;
            }
            level = max(level, new_l);
        }
        length ++;
    }
    
    bool erase(int num) {
        vector<skiplistNode*> update(level, nullptr);

        struct skiplistNode* x = head;
        for(int l = level-1; l >= 0; l--){
            // x->key < target
            while(x->forwards[l] != nullptr 
                    && x->forwards[l]->key < num){
                x = x->forwards[l];
            }
            update[l] = x;
        }
        x = x->forwards[0];

        if(x == nullptr || x->key != num){
            return false;
        }

        for(int l = 0; l<level; ++l){
            if(update[l]->forwards[l] != x){
                break;
            }
            update[l]->forwards[l] = x->forwards[l];
        }

        delete x;
        length --;

        while(level > 1 && head->forwards[level - 1]== nullptr){
            level--;
        }

        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */


void test1206(){
    Skiplist* obj = new Skiplist();
    obj->add(1);
    obj->add(2);
    obj->add(3);
    cout << obj->search(0) << endl;
    obj->add(4);
    cout << obj->search(1) << endl;
    cout << obj->erase(0) << endl;
    cout << obj->erase(1) << endl;
    cout << obj->search(1) << endl;
}


#endif // !_LIST_LEETCODE1206_H_