/*
塔子哥从一副扑克牌中随机抽取𝑛张牌组成一个序列，规定：连续3张相同牌号的卡牌可以消除，剩余卡牌按照当前顺序重新合并成新的序列后继续消除，例如序列 
01112
01112 在消除 
111
111 之后，余下 
02
02，重复以上步骤直到无法消除，请你完成这个游戏，输出结束后剩余的卡牌序列。

注：存在连续4张相同牌号的情况，消除后剩余一张。

输入描述
第一行输入一个整数n，表示抽出扑克牌的数量。其中1≤n≤52。

第二行一个字符串，以空格分隔代表卡牌号序列，卡牌号仅包含2-10，A，J，Q，K

输出描述
输出一个字符串，表示最终的卡牌序列，卡牌号以空格分隔。

当所有扑克牌都被消除，输出
0
*/

#ifndef __COMPARE_H__
#define __COMPARE_H__

void test_0417_01(){
    int n;
    cin >> n;

    vector<char> temp; 
    for(int i = 0; i<n; ++i){
        char ch;
        cin >> ch;
        if(temp.size() >= 2 && temp[temp.size()-1] == ch && temp[temp.size()-2] == ch){
            temp.pop_back();
            temp.pop_back();
        }else{
            temp.push_back(ch);
        }
    }

    if(temp.empty()){
        cout << "0" << endl;
    }else{
        for(auto x: temp){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

#endif // __COMPARE_H__