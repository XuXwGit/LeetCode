/*
LCR 170. 交易逆序对的总数
困难
相关标签
相关企业
在股票交易中，如果前一天的股价高于后一天的股价，则可以认为存在一个「交易逆序对」。请设计一个程序，输入一段时间内的股票交易记录 record，返回其中存在的「交易逆序对」总数。


示例 1:

输入：record = [9, 7, 5, 4, 6]
输出：8
解释：交易中的逆序对为 (9, 7), (9, 5), (9, 4), (9, 6), (7, 5), (7, 4), (7, 6), (5, 4)。
*/

#ifndef __LEETCODE_LCR_170_H__
#define __LEETCODE_LCR_170_H__

class SolutionLCR170 {
private:
    int count = 0;
    void merge(vector<int>& nums, int left, int right){
        if(left == right){
            return;
        }
        int mid = left + (right - left)/2;
        merge(nums, left, mid);
        merge(nums, mid + 1, right);
        merge_sort(nums, left, right);
    }

    void merge_sort(vector<int>& nums, int left, int right){
        int mid = left + (right - left)/2;
        vector<int> temp;
        int l1 = left, l2 = mid + 1;

        while(l1 <= mid && l2 <= right){
            if(nums[l1] <= nums[l2]){
                temp.push_back(nums[l1]);
                l1 ++;
            }else{
                count += (mid - l1 + 1);
                temp.push_back(nums[l2]);
                l2 ++;
            }
        }

        while(l1 <= mid){
            temp.push_back(nums[l1]);
            l1 ++;
        }

        while(l2 <= right){
            temp.push_back(nums[l2]);
            l2 ++;
        }

        for(int i = 0; i < temp.size(); ++i){
            nums[left + i] = temp[i];
        }
    }
public:
    int reversePairs(vector<int>& record) {
        if(record.size() <= 1){
            return 0;
        }

        merge(record, 0, record.size() - 1);
        return count;
    }
};


void test_LCR_170(){
    vector<int> record = {9, 7, 5, 4, 6};
    SolutionLCR170 solution;
    cout << solution.reversePairs(record) << endl;
}


#endif // __LEETCODE_LCR_170_H__