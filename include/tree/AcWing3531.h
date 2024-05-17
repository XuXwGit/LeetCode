/*
3531. 哈夫曼树

给定 N 个权值作为 N 个叶子结点，构造一棵二叉树，若该树的带权路径长度达到最小，称这样的二叉树为最优二叉树，也称为哈夫曼树(Huffman Tree)。

现在，给定 N 个叶子结点的信息，请你构造哈夫曼树，并输出该树的带权路径长度。

相关知识：
1、路径和路径长度在一棵树中，从一个结点往下可以达到的孩子或孙子结点之间的通路，称为路径。通路中分支的数目称为路径长度。若规定根结点的层数为 1
，则从根结点到第 L 层结点的路径长度为 L−1。
2、结点的权及带权路径长度
若将树中结点赋给一个有着某种含义的数值，则这个数值称为该结点的权。结点的带权路径长度为：从根结点到该结点之间的路径长度与该结点的权的乘积。
3、树的带权路径长度
树的带权路径长度规定为所有叶子结点的带权路径长度之和，记为 WPL。

输入格式
第一行包含整数 N，表示叶子结点数量。

第二行包含 N 个整数，表示每个叶子结点的权值。

输出格式
输出一个整数，表示生成哈夫曼树的带权路径长度。

数据范围 2≤N≤1000,
叶子结点的权值范围 [1,100]。

*/

#ifndef _TREE_ACWING3531_H_
#define _TREE_ACWING3531_H_


using namespace std;


void huffman_tree(){
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    int num;
    while(n -- ){
        cin >> num;
        pq.push(num);
    }
    
    int res = 0;
    while(pq.size() > 1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        pq.push(x + y);
        res += x+y;
    }
    
    cout << res << endl;
}

#endif // !_TREE_ACWING3531_H_