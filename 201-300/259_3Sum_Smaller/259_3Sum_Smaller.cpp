#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int result = 0;
        if(nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            if(nums[i] + nums[i + 1] + nums[i + 2] >= target) {
                break;
            }
            int left = i + 1, right = nums.size() - 1;
            while(left < right) {
                if(nums[i] + nums[left] + nums[right] >= target) {
                    right--;
                } else {
                    result += right - left;
                    left++;
                }
            }
        }
        return result;
    }
};

int main() {
	vector<int> nums = {-2, 0, 1, 3};
	int target = 2;
	Solution s;
	cout << s.threeSumSmaller(nums, target) << endl;
	return 0;
}