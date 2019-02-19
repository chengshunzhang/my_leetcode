#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            } else if(nums[mid] == nums[mid - 1]){
                if(mid % 2 == 0) {
                    right = mid;
                } else {
                    left = mid;
                }
            } else {
                if(mid % 2 == 1) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
        }
        if(left == 0 || nums[left] != nums[left - 1]) {
            return nums[left];
        }
        return nums[right];
    }
};

int main() {
	Solution s;
	vector<int> nums = {1,1,2,3,3,4,4,8,8};
	cout << s.singleNonDuplicate(nums) << endl;
	return 0;
}