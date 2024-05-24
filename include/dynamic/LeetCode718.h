/*
718. 最长重复子数组
已解答
中等
相关标签
相关企业
提示
给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。



示例 1：

输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 。
示例 2：

输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
输出：5


提示：

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
*/

#ifndef _DYNAMIC_LEETCODE718_H_
#define _DYNAMIC_LEETCODE718_H_

class Solution718
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (nums1[i] != nums2[j])
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (i > 0 && j > 0)
                    {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    else
                    {
                        dp[i][j] = 1;
                    }
                }
            }
        }

        int maxLen = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                maxLen = max(maxLen, dp[i][j]);
            }
        }

        return maxLen;
    }
};

void test718()
{
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    Solution718 solution718;
    cout << solution718.findLength(nums1, nums2) << endl;
}

#endif // _DYNAMIC_LEETCODE718_H_