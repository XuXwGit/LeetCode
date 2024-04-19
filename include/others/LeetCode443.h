#ifndef LEETCODE_443_H
#define LEETCODE_443_H

#include <vector>
#include <iostream>

using namespace std;

class Solution443 {
public:
    int compress(vector<char>& chars) {
        int res = 0;

        int left = 0;
        int len = 1;
        int num = 0;

        while(left < chars.size()){
            len = 1;
            while(left + len < chars.size() && chars[left + len] == chars[left]){
                len ++;
            }
            res += 1 + (len/10 + 1);

            chars[num++] = chars[left];
            left = left + len;
            while(len/10){
                chars[num++] = (char)(len/10 + '0');
                len = len/10;
            }
            chars[num++] = (char)(len + '0');

        }

        return res;
    }
};

void test443(){
    Solution443 solution;

    vector<char> chars = {'a','a','b','b','c','c','c'};
    cout << solution.compress(chars) << endl;
    for(int i = 0; i < chars.size(); i ++){
        cout << chars[i] << " ";
    }
}

#endif