#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int findKth(vector<int>& nums1, vector<int>& nums2, int K) {
        int start1 = 0, start2 = 0, m = nums1.size(), n = nums2.size();
        while(K > 1) {
            if(start1 >= m) {
                return nums2[start2 + K - 1];
            }
            if(start2 >= n) {
                return nums1[start1 + K - 1];
            }
            int val1 = start1 + K / 2 > m ? INT_MAX : nums1[start1 + K / 2 - 1];
            int val2 = start2 + K / 2 > n ? INT_MAX : nums2[start2 + K / 2 - 1];
            if(val1 < val2) {
                start1 += K / 2;
            } else {
                start2 += K / 2;
            }
            K -= K / 2;
        }
        if(start1 >= m) {
            return nums2[start2];
        }
        if(start2 >= n) {
            return nums1[start1];
        }
        return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int first = findKth(nums1, nums2, (m + n + 1) / 2);
        int second = findKth(nums1, nums2, (m + n + 2) / 2);
        return (first + second) / 2.;
    }
};

int main() {
	Solution s;
	vector<int> nums1 = {1, 3};
	vector<int> nums2 = {2};
	cout << s.findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}