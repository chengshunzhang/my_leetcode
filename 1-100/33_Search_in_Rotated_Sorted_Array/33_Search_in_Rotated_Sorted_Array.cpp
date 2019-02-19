#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
        if(nums.empty()) {
            return -1;
        }
		int left = 0, right = nums.size() - 1;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(target == nums[mid]) {
                return mid;
            }
            if(nums[mid] < nums[right]) {
                if(target > nums[mid] && target < nums[right]) {
                    left = mid;
                } else if(target == nums[right]) {
                    return right;
                } else { //target > nums[right] || target < nums[mid]
                    right = mid;
                }
            } else {
                if(target == nums[left]) {
                    return left;
                } else if(target > nums[left] && target < nums[mid]) {
                    right = mid;
                } else { //target < nums[left] || target > nums[mid]
                    left = mid;
                }
            }
        }
        if(nums[left] == target) {
            return left;
        }
        if(nums[right] == target) {
            return right;
        }
        return -1;
    }
};

int main() {
	int target = 3;
	vector<int> nums = {0,1,2,3,4,5,6};
	Solution s;
	cout << s.search(nums, target) << endl;
	return 0;
}