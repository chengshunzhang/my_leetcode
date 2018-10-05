#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() - 1, left = 0, right = n;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            int midval = nums[mid], leftval = nums[mid - 1], rightval = nums[mid + 1];
            if(midval > rightval && midval > leftval) {
                return mid;
            } else if((midval < leftval && midval < rightval) || (midval > leftval && rightval > midval)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if(nums[left] > nums[right]) {
            return left;
        } else {
            return right;
        }
    }
};

int main() {
	int n[] = {1,2,3,1};
	vector<int> nums(n,n+4);
	Solution s;
	cout << s.findPeakElement(nums) << endl;
	return 0;
}