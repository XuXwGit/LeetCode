/*
658. 找到 K 个最接近的元素
已解答

给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

整数 a 比整数 b 更接近 x 需要满足：

|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b
*/

#ifndef _LEETCODE_BINARYSEARCH_LEETCODE658_H_
#define _LEETCODE_BINARYSEARCH_LEETCODE658_H_



class Solution658 {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        int mid = 0;
        while(left < right){
            mid = left + (right - left)/2;
            if((x - arr[mid]) > (arr[mid + k] - x)){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        vector<int> res;
        for(int i = left; i<left + k; ++i){
            res.push_back(arr[i]);
        }
        return res;
    }
};

void test658(){
    //[1,1,2,2,2,2,2,3,3]
    //k = 3
    //x = 3
    vector<int> arr = {1,1,2,2,2,2,2,3,3};
    int k = 3;
    int x = 3;
    Solution658 solution;
    auto res = solution.findClosestElements(arr, k, x);
    for(auto num : res){
        cout << num << " ";
    }
}

#endif // !_LEETCODE_BINARYSEARCH_LEETCODE658_H_