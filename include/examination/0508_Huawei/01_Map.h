#ifndef _01_MAP_H_
#define _01_MAP_H_

/*
虚拟机约定：32位的整形寄存器有
𝑎
0
a 
0
​
 ,
𝑎
1
a 
1
​
 ,..
𝑎
31
a 
31
​
 ，共32个寄存器；

整个虚拟机只有寄存器和立即数参与计算。

规则集（dst一定为寄存器，src为寄存器或十进制正整数，运算结果存在负数场景）：

（1）MOV dst src
含义:dst = src

（2）ADD dst src0 src1
含义:dst = src0 + src1

（3）SUB dst src0 src1
含义:dst = src0 - src1

（4）MUL dst src0 src1
含义:dst = src0 * src1

（5）DIV dst src0 src1
含义:dst = src0 / src1(结果向下取整)

（6）PRINT dst
含义:打印dst寄存器值

规定：不用考虑计算溢出(用例保证)，指令数最多100条，至少一条PRINT指令，寄存器保证先赋值再引用。不用考虑小数以及除0错误。

输入描述
若干行，每行一条指令

输出描述
对输入的每行指令，若为PRINT指令，则输出打印一行，该行中包括一个整数，表示寄存器的值
*/

unordered_map<string, int> maps;

int str_to_int(string str){
    int res = 0;

    if(str[0] == '-'){
        for(int i = 1; i<(int)str.size(); ++i){
            res = res * 10 + (str[i] - '0');
        }
        return -res;
    }else{
        for(int i = 0; i<(int)str.size(); ++i){
            res = res * 10 + str[i] - '0';
        }
        return res;
    }

    return res;
}

int resolve(const string& src){
    return maps.count(src) ? maps[src] : str_to_int(src);
}

void test_0508_01(){
    string str;
    
    while(cin >> str){
        if(str == "MOV"){
            string dst, src;
            cin >> dst >> src;
            maps[dst] = resolve(src);
        }else if(str == "PRINT"){
            string dst;
            cin >> dst;
            cout << maps[dst] << endl;
        }else if(str == "ADD"){
            string dst,src0,src1;
            cin >> dst >> src0 >> src1;
            maps[dst] = resolve(src0) + resolve(src1);
        }else if(str == "SUB"){
            string dst, src0, src1;
            cin >> dst >> src0 >> src1;
            maps[dst] = resolve(src0) - resolve(src1);
        }else if(str == "MUL"){
            string dst, src0, src1;
            cin >> dst >> src0 >> src1;
            maps[dst] = resolve(src0) * resolve(src1);
        }else if(str == "DIV"){
            string dst, src0, src1;
            cin >> dst >> src0 >> src1;
            // floor() : 向下取整
            // ceil()  : 向上取整
            // round() : 四舍五入
            // trunc() : 向0取整
            maps[dst] = floor((1.0 * resolve(src0)) / resolve(src1));
        }
    }
}


#endif