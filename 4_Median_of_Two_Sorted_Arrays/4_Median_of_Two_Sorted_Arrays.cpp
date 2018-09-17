#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0) {
            int n = nums2.size();
            return n % 2 == 0 ? (nums2[n / 2 - 1] + nums2[n / 2]) / 2. : nums2[n / 2];
        }
        else if (nums2.size() == 0) {
            int n = nums1.size();
            return n % 2 == 0 ? (nums1[n / 2 - 1] + nums1[n / 2]) / 2. : nums1[n / 2];
        }
        else {
            vector<int>::iterator itr1 = nums1.begin();
            vector<int>::iterator itr2 = nums2.begin();
            int m = nums1.size();
            int n = nums2.size();
            int count = 0, previous = 0;
            while (count < (m + n) / 2) {
                if (itr1 == nums1.end() || itr2 == nums2.end())
                    break;
                if (*itr1 < *itr2) {
                    itr1++;
                    previous = 1;
                }
                else {
                    itr2++;
                    previous = 2;
                }
                count++;
            }
            bool firstempty = (itr1 == nums1.end()) ? true : false;
            while (count < (m + n) / 2) {
                if (firstempty) {
                    itr2++;
                    previous = 2;
                }
                else {
                    itr1++;
                    previous = 1;
                }
                count++;
            }
            int next;
            if (itr1 == nums1.end())
                next = *itr2;
            else if (itr2 == nums2.end())
                next = *itr1;
            else
                next = *itr1 < *itr2 ? *itr1 : *itr2;
            if ((m + n) % 2 == 1)
                return double(next);
            else {
                previous == 1 ? previous = *(--itr1) : previous = *(--itr2);
                return (previous + next) / 2.;
            }
        }
    }
};

int main(){
    int n1[] = {1}, n2[] = {2,3,4};
    vector<int> nums1(n1,n1+1);
    vector<int> nums2(n2,n2+3);
    Solution s;
    cout << s.findMedianSortedArrays(nums1,nums2) << endl;
    return 0;
}