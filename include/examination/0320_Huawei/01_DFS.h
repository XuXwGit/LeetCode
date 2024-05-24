/*
2024.3.20-HW-第一题-塔子哥安排座位
题目描述
一列具有 m 个座位的火车，从起点到终点共停靠 n 个站点，站点编号从0到n-1。发车前有x名乘客预定了座位，因为预定数量可能超出座位数，为了保证效率最大化，请计算如何分配才能是座位利用率最大，并输出最大的座位利用数。

说明:

座位利用数定义为每个座位被使用的站数。例如有两个座位，第一个座位从第 0到 10 站有人坐(表示从0站上车，10站下车，第10站不占座，所以利用率是10-0=10)，第二个座位从第1到9站有人坐，则座位利用率为(10-0)+(9-1)=18。乘客在某站下车后，其他乘客从这一站就可以开始使用这个座位;无需考虑乘客需要更换座位的问题，保证任意时刻列车上乘客数量不超过 m 即可

输入描述
第一行输入 m、n和x三个数字，分别表示列车座位数量、停靠站点数量和预定乘客数量

1 <= m <= 9

2 <= n <= 20

1 <= x <= 9

接下来x行输入，表示x条预定记录，每行有两个输入，分别表示此预定记录的上车站点和下车站点

输出描述
一个整数。

样例
输入

2 11 4
0 1
1 9
0 10
3 8
输出

19
说明

选择前三位乘客可以使座位利用率最大:19=(1-0)+(9-1)+(10-0)。若选择后两位乘客，则利用率为15=(10-0)+(8-3)。若选择全部四位乘客，则第3到8站车上存在3名乘客，超出列车座位数。
*/

#ifndef _EXAMINATION_HUAWEI_0320_01_H_
#define _EXAMINATION_HUAWEI_0320_01_H_

using namespace std;

class solution_HW_0320_01
{
private:
    vector<int> starts;
    vector<int> ends;
    int capacity;
    int numports;
    int num_customers;

    int max_used;

    int dfs(int level, vector<int> res)
    {
        if (level == num_customers)
        {
            return 0;
        }

        // not select customer l
        int sel = dfs(level + 1, res);
        // select customer l
        for (int i = starts[level]; i < ends[level]; ++i)
        {
            res[i]--;
            if (res[i] < 0)
            {
                return sel;
            }
        }
        sel = max(sel, dfs(level + 1, res) + ends[level] - starts[level]);

        return sel;
    }

public:
    int getMaxUsed(int m, int n, vector<int> &start, vector<int> &end)
    {
        capacity = m;
        numports = n;
        num_customers = start.size();
        starts = start;
        ends = end;
        max_used = 0;
        vector<int> res(numports, capacity);
        return dfs(0, res);
    }
};

/*
2 11 4
0 1
1 9
0 10
3 8
*/
void test_0320_01()
{
    int m = 2, n = 11, x = 4;

    vector<int> start = {0, 1, 0, 3};
    vector<int> end = {1, 9, 10, 8};

    solution_HW_0320_01 sol;
    cout << sol.getMaxUsed(m, n, start, end);
}

#endif // !_EXAMINATION_HUAWEI_0320_01_H_