#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]) {
                left = mid;
            } else if(nums[mid] < nums[right]) {
                right = mid;
            }
        }
        return nums[left] < nums[right] ? nums[left] : nums[right];
    }
};

int main() {
	int n[] = {1,2,3};
	vector<int> nums(n,n+3);
	Solution s;
	cout << s.findMin(nums) << endl;
	return 0;
}