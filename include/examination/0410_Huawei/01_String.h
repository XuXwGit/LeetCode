/*




*/

#ifndef EXAMINATION_0410_HUAWEI_01_STRING_H
#define EXAMINATION_0410_HUAWEI_01_STRING_H

#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> split(string line, char ch)
{
    vector<string> res;

    int left = 0;
    int len = 0;

    cout << line << endl;

    while (left + len < (int)line.size())
    {
        if (line[left + len] == ch)
        {
            res.push_back(line.substr(left, len));
            left = left + len + 1;
            len = 0;
        }
        len++;
    }
    res.push_back(line.substr(left, len));

    for (auto x : res)
    {
        cout << x << ch;
    }
    cout << endl;

    return res;
}

void solution(vector<string> &times, vector<string> &cilents, vector<string> &factors, vector<int> &costs, unordered_map<string, int> &maps)
{
    int n = times.size();
    map<string, pair<int, string>> cilentcosts;
    for (int i = 0; i < n; ++i)
    {
        if (cilentcosts.count(cilents[i]))
        {
            if (times[i] + factors[i] == cilentcosts[cilents[i]].second)
            {
                continue;
            }
            else
            {
                cilentcosts[cilents[i]].first += costs[i] * maps[factors[i]];
            }
        }
        else
        {
            cilentcosts[cilents[i]].second = times[i] + factors[i];
            cilentcosts[cilents[i]].first += costs[i] * maps[factors[i]];
        }
    }

    for (auto x : cilentcosts)
    {
        cout << x.first << "," << x.second.first << endl;
    }
}

void test_0410_01()
{

    // 5
    // 1627845600, client1, factorA, 10
    // 1627845605, client2, factorB, 15
    // 1627845610, client1, factorA, 5
    // 1627845615, client1, factorB, 8
    // 1627845620, client2, factorB, 20
    // 2
    // factorA, 5
    // factorB, 7

    int n = 5;

    vector<string> lines = {
        "1627845600, client1, factorA, 10",
        "1627845605, client2, factorB, 15",
        "1627845610, client1, factorA, 5",
        "1627845615, client1, factorB, 8",
        "1627845620, client2, factorB, 20"};

    vector<string> times;
    vector<string> cilents;
    vector<string> factors;
    vector<int> costs;

    string line;
    for (int i = 0; i < n; ++i)
    {
        // getline(cin, line);
        line = lines[i];
        vector<string> temp = split(line, ',');

        int cost = stoi(temp[3]);

        if (cost < 0 || cost > 100)
        {
            cost = 0;
        }

        times.push_back(temp[0]);
        cilents.push_back(temp[1]);
        factors.push_back(temp[2]);
        costs.push_back(cost);
    }

    int m = 2;
    vector<string> factors_costs = {
        "factorA, 5",
        "factorB, 7"};
    unordered_map<string, int> maps;
    for (int i = 0; i < m; ++i)
    {
        // getline(cin, line);
        line = factors_costs[i];
        vector<string> temp = split(line, ',');
        maps[temp[0]] = stoi(temp[1]);
    }

    solution(times, cilents, factors, costs, maps);
}

#endif // EXAMINATION_0410_HUAWEI_01_STRING_H