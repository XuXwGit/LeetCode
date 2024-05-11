/*
460. LFU 缓存
请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。

实现 LFUCache 类：

LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
int get(int key) - 如果键 key 存在于缓存中，则获取键的值，否则返回 -1 。
void put(int key, int value) - 如果键 key 已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量 capacity 时，则应该在插入新项之前，移除最不经常使用的项。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最久未使用 的键。
为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。
*/

#ifndef _DYNAMIC_PROGRAMMING_LEETCODE460_H_
#define _DYNAMIC_PROGRAMMING_LEETCODE460_H_


class LFUCache {
private:
    struct Node{
        int key;
        int val;
        int freq;
        Node(int key, int val, int freq):key(key), val(val), freq(freq){}
    };

    int minFreq;
    int capacity;
    unordered_map<int, Node*> caches;
    unordered_map<int, list<Node*>> freqs;
public:
    LFUCache(int capacity): capacity(capacity), minFreq(1){
    }
    
    int get(int key) {
        if(caches.count(key)){
            Node* node = caches[key];
            freqs[node->freq].remove(node);
            if(freqs[node->freq].empty()){
                freqs.erase(node->freq);
                if(node->freq == minFreq){
                    minFreq ++;
                }
            }
            freqs[node->freq + 1].push_front(node);
            node->freq++;
            return node->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(caches.count(key)){
            Node* node = caches[key];
            freqs[node->freq].remove(node);
            if(freqs[node->freq].empty()){
                freqs.erase(node->freq);
                if(node->freq == minFreq){
                    minFreq ++;
                }
            }
            freqs[node->freq + 1].push_front(node);
            node->freq ++;
            node->val = value;
        }else{
            Node* node = new Node(key, value, 1);
            if(caches.size() == capacity){
                Node* temp = freqs[minFreq].back();
                caches.erase(temp->key);
                freqs[minFreq].pop_back();
                if(freqs[minFreq].size() == 0){
                    freqs.erase(minFreq);
                }
            }
            caches[key] = node;
            freqs[1].push_front(node);
            minFreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

void test460(){
    LFUCache* obj = new LFUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    obj->put(3, 3);
    cout << obj->get(2) << endl;
    cout << obj->get(3) << endl;
    obj->put(4, 4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
}


#endif // !_DYNAMIC_PROGRAMMING_LEETCODE460_H_