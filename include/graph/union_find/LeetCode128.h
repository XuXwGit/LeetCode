/*
128. 最长连续序列
已解答
中等

给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

*/


#ifndef _GRAPH_UNION_FIND_LEETCODE128_H_
#define _GRAPH_UNION_FIND_LEETCODE128_H_


class Solution128 {
private:
    vector<int> parent;
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void merge(int x, int y){
        int p_x = find(x);
        int p_y = find(y);
        if(p_x != p_y){
            parent[p_x] = p_y;
        }
    }
public:
    int longestConsecutive(vector<int>& nums) {
        parent = vector<int>(nums.size());
        
        for(int i = 0; i<nums.size(); ++i){
            parent[i] = i;
        }

        map<int, int> numsmap;
        map<int, int> count;
        for(int i = 0; i<nums.size(); ++i){
            int x = nums[i];
            if(numsmap.count(x)){
                continue;
            }
            if(numsmap.count(x - 1)){
                merge(i, numsmap[x-1]);
            }
            if(numsmap.count(x + 1)){
                merge(i, numsmap[x + 1]);
            }
            numsmap[x] = i;
            count[i] = 1;
        }

        
        for(auto x: numsmap){
            if(find(x.second) != x.second){
                count[find(x.second)] ++;
            }
        }

        int maxlen = 0;
        for(auto x: count){
            maxlen = max(maxlen, x.second );
        }

        return maxlen;
    }
};


void test128(){
    Solution128 s;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(nums) << endl;

    // [1,2,0,1]
    nums = {1, 2, 0, 1};
    cout << s.longestConsecutive(nums) << endl;
}

#endif // _GRAPH_UNION_FIND_LEETCODE128_H_