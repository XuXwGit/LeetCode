/*
足球队一共有𝑛个队员，塔子哥安排他们参与𝑚次点球射门，每次射中用11表示，射失（没射中）用0
0表示，塔子哥为他的球员能力强弱拟定了如下标准：

（1）进球总数更多的队员射门能力更强；

（2）若进球总数一样多，则比较最多一次连续进的个数，更多的队员能力更强；

（3）若最多一次连续进球个数一样多，则比较第一次射失的先后顺序，其中后射失的队员更强，若第一次射失顺序相同，则按继续比较第二次射失的顺序，后丢球的队员能力更强，依次类推；

（4）若前3个规则排序后还能力相等，则队员编号更小的能力更强。

输入描述
第一行输入两个整数𝑛和𝑚，分别表示足球队中队员的数量，以及射门训练的次数。（队员编号从1开始，依次递增）
2𝑛−12 n
 −1个整数，表示整棵满二叉搜索树。其中
1≤𝑛≤10
1≤n≤10，整数之间用空格分割。

第二行，第11~𝑛个队员从第11到𝑚m次训练的进球情况，每个队员进球情况为连续的11和00的组合，不同队员的情况用空格分隔

规定：所有𝑛和𝑚均为整数
1≤𝑛,𝑚≤1000
1≤n,m≤1000。

输出描述
所有球员射门能力从强到弱的队员编号，用空格分隔每个编号
*/


#ifndef __COMPARE_H__
#define __COMPARE_H__

#include<bits/stdc++.h>
using namespace std;

struct sporter{
    int id;
    int count_ones;
    int countinues;
    string result;

    bool operator<(const sporter& right) const{
        if(this->count_ones != right.count_ones){
            return count_ones > right.count_ones;
        }else{
            if(this->countinues != right.countinues){
                return this->countinues > right.countinues;
            }else{
                if(this->result != right.result){
                    return this->result > right.result;
                }else{
                    return this->id < right.id;
                }
            }
        }
    }

    sporter(int id, string result)
    : id(id), result(result){
        count_ones = 0;
        int zero_pos = -1;
        countinues = 0;
        for(int i = 0; i<(int)result.size(); ++i){
            if(result[i] == '0'){
                zero_pos = i;
            }else{
                count_ones ++;
                countinues = max(countinues, i - zero_pos);
            }
        }
    }
};

void test_0424_02(){
    int n, m;
    cin >> n >> m;
    set<sporter> sps;
    string str = "";
    for(int i = 1; i<=n; ++i){
        cin >> str;
        sps.emplace(i, str);
    }

    for(auto x: sps){
        cout << x.id << " ";
    }
    cout << endl;
}


#endif // __COMPARE_H__