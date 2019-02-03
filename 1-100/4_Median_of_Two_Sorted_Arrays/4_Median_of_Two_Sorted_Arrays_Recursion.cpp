#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int findKth(vector<int>& nums1, vector<int>& nums2, int start1, int start2, int K) {
        if(start1 >= nums1.size()) {
            return nums2[start2 + K - 1];
        }
        if(start2 >= nums2.size()) {
            return nums1[start1 + K - 1];
        }
        if(K == 1) {
            return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
        }
        int val1 = start1 + K / 2 > nums1.size() ? INT_MAX : nums1[start1 + K / 2 - 1];
        int val2 = start2 + K / 2 > nums2.size() ? INT_MAX : nums2[start2 + K / 2 - 1];
        if(val1 < val2) {
            return findKth(nums1, nums2, start1 + K / 2, start2, K - K / 2);
        } else {
            return findKth(nums1, nums2, start1, start2 + K / 2, K - K / 2);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int first = findKth(nums1, nums2, 0, 0, (m + n + 1) / 2);
        int second = findKth(nums1, nums2, 0, 0, (m + n + 2) / 2);
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