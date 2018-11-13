#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, last = m + n -1;
        while(p1 > -1 && p2 > -1) {
            if(nums1[p1] > nums2[p2]) {
                nums1[last--] = nums1[p1];
                p1--;
            } else {
                nums1[last--] = nums2[p2];
                p2--;
            }
        }
        while(p2 > -1) {
            nums1[last--] = nums2[p2--];
        }
    }
};

int main() {
	int n1[] = {1,2,3,0,0,0}, m = 3, n2[] = {2,4,6}, n = 3;
	Solution s;
	vector<int> nums1(n1, n1 + 6), nums2(n2, n2 + 3);
	s.merge(nums1, m, nums2, n);
	for(int i = 0; i < m + n; i++) {
		cout << nums1[i] << ' ';
	}
	cout << endl;
	return 0;
}