#ifndef _LEETCODE_4_H_
#define _LEETCODE_4_H_

#include <vector>
#include <numeric>

using namespace std;

class Solution4 {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int left = 0;
    int right = nums1.size() ;
    int mid1 = 0;
    int mid2 =0;
    int flag = (nums1.size() + nums2.size()) % 2;

    int left_max = 0;
    int right_min = 0;

    while (left <= right) {
      mid1 = (left + right) / 2;
      mid2 = (nums1.size() + nums2.size() + 1) / 2 - mid1;
      if (mid2 == nums2.size()-1 || (mid2 < nums2.size() - 1 && nums1[mid1] <= nums2[mid2])) {
        left_max = mid1 == 0 ? nums2[mid2 - 1] : (mid2 == 0 ? nums1[mid1 - 1] : max(nums1[mid1 - 1], nums2[mid2 - 1]));
		right_min = mid1 == nums1.size() ? nums2[mid2] : (mid2 == nums2.size() ? nums1[mid1] : min(nums1[mid1], nums2[mid2]));
		if (flag == 1) {
		  return left_max;
		} else {
		  return (left_max + right_min) / 2.0;
		}
	  } else if (mid1 == nums1.size() || (mid1 < nums1.size() && nums1[mid1] > nums2[mid2])) {
		right = mid1 - 1;
	  } else {
		left = mid1 + 1;
      }
    }

    return 0.0;
  }
};

void test4() {
  vector<int> vec1 = {1, 3};
  vector<int> vec2 = {2, 7};
  Solution4 solution4;
  cout << solution4.findMedianSortedArrays(vec1, vec2) << endl;
}


#endif  // !_LEETCODE_4_H_
