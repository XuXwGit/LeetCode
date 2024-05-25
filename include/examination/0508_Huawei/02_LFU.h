/*
2024.5.8-HW-第二题-塔子哥的计网实验
题目描述
这学期的塔子哥的计网老师教学水平真是一言难尽，还要用ensp来做一些繁琐的模拟实验，但是计网实验跟写代码有什么关系呢？来不及为赶不完的DDL哀悼了，有一个实验描述如下：

无线通信移动性需要在基站上配置邻区(本端基站的小区LocalCell与周边邻基站的小区NeighborCelI映射)关系，为了能够加速无线算法的计算效率，设计一个邻区关系缓存表，用于快速的通过本小区LocalCell查询到邻小区NeighborCell。但是缓存表有一定的规格限制，因此到达规格并且需要插入新的数据时，需要删除邻区数据，选择删除邻区数据对象的策略为：

（1）使用次数最少的；

（2）如果（1）返回有多个对象,则选择最久未使用的。

请设计并实现一个满足以上要求的数据结构和算法实现。

注:假设每个LocalCell至多只有一个NeighborCell。

输入描述
 1、首行以字符"capacity:"标识设置一个整数容量;

 2、以"write:"标识开始进行若干组[LocalCell,NeighborCell]邻区数据的输入,每组数据为一行;如果"write:"已经存在的LocalCell数据,更新其对 应的NeighborCell,并刷新使用时间和次数加1;如果某邻区数据被删除,缓存表不再保留其记录;

 3、以"read:"标识进行一次读取LocalCell的使用操作,刷新使用时间和次数加1;

 4、最后以"query:"标识查询输出操作，输入正整数LocalCell，查询NeighborCell；

注:

（1）写入和读取都表示对LocalcelI的使用操作;

（2）capacity、LocalCellI和NeighborCelI都是正整数，范围在[1,10000];

（3）输入的总行数不超过30000行。

输出描述
每个查询输入正整数LocalCell对应NeighborCell，表示在邻区关系缓存表中的记录。

 1、找到，则返回NeighborCell；
 2、没有找到，则返回-1;

样例一
输入

capacLy:
3
write:
3
1 2
4 3
2 3
read:
2
write:
1
3 1
query:
1
输出

-1
解释

 1、设定容量capacity为3

 2、write输入3组数据，

 3、read读取2使用,刷新该邻区对使用时间和次数;

 4、再write输入1组数据,因为已经超了容量3,所以把最早输入且未使用的数据”12”剔除;

 5、最后进行query查询1因为已经被剔除了,所以返回-1;
*/

#ifndef _EXAMINATION_0508_HUAWEI_02_LFU_H_
#define _EXAMINATION_0508_HUAWEI_02_LFU_H_

#include <bits/stdc++.h>

using namespace std;

class LFUcaches
{
private:
    struct doubleListNode
    {
        int key;
        int val;
        int counts;

        doubleListNode(int key, int val, int count) : key(key), val(val), counts(count) {}
    };
    int capacity;
    int min_count;
    unordered_map<int, doubleListNode *> caches;
    unordered_map<int, list<doubleListNode *>> freqes;

    doubleListNode *removeNode(doubleListNode *node)
    {
        freqes[node->counts].remove(node);
        if (freqes[node->counts].empty())
        {
            freqes.erase(node->counts);
        }
        return node;
    }

    void insertNode(doubleListNode *node, int count)
    {
        if (node->counts != count)
        {
            node->counts = count;
        }
        freqes[count].push_front(node);
    }

    void update(doubleListNode *node)
    {
        node = removeNode(node);
        if (min_count == node->counts && !freqes.count(min_count))
        {
            min_count++;
        }
        insertNode(node, node->counts + 1);
    }

public:
    LFUcaches(int capacity) : capacity(capacity) {}

    void write(int key, int val)
    {
        if (caches.count(key))
        {
            doubleListNode *node = caches[key];
            update(node);
            node->val = val;
        }
        else
        {
            if ((int)caches.size() == capacity)
            {
                doubleListNode *node = freqes[min_count].back();
                node = removeNode(node);
                caches.erase(node->key);
                delete node;
            }

            doubleListNode *node = new doubleListNode(key, val, 1);
            caches[key] = node;
            freqes[1].push_front(node);
            min_count = 1;
        }
    }

    int search(int key)
    {
        if (caches.count(key))
        {
            doubleListNode *node = caches[key];
            update(node);
            return caches[key]->val;
        }
        else
        {
            return -1;
        }
    }

    int query(int key)
    {
        if (caches.count(key))
        {
            return caches[key]->val;
        }
        else
        {
            return -1;
        }
    }
};
void test_0508_02()
{
    string str;
    int capacity = 3;
    // cin >> capacity;
    LFUcaches lfu(capacity);

    vector<string> strs = {"write:", "read:", "query:"};
    // while (cin >> str)
    for (auto str : strs)
    {
        if (str == "write:")
        {
            int n = 3;
            // cin >> n;
            int key, val;
            vector<int> keys = {3, 4, 2};
            vector<int> vals = {1, 3, 3};
            for (int i = 0; i < n; ++i)
            {
                // cin >> key >> val;
                key = keys[i];
                val = vals[i];
                lfu.write(key, val);
            }
        }
        else if (str == "read:")
        {
            int n = 2;
            // cin >> n;
            lfu.search(n);
        }
        else if (str == "query:")
        {
            int n = 1;
            // cin >> n;
            cout << lfu.query(n) << endl;
        }
    }
}

#endif // _EXAMINATION_0508_HUAWEI_02_LFU_H_