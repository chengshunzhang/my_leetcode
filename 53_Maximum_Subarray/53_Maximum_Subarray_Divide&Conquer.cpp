#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
private:
    int helper(vector<int>& nums, int left, int right) {
        if(left >= right) {
            return nums[left];
        }
        int mid = left + (right - left) / 2;
        int sum_left = helper(nums, left, mid - 1);
        int sum_right = helper(nums, mid + 1, right);
        int sum_across = nums[mid];
        int sumNow = sum_across;
        for(int i = mid - 1; i > -1; i--) {
            sumNow += nums[i];
            if(sumNow > sum_across) {
                sum_across = sumNow;
            }
        }
        sumNow = sum_across;
        for(int i = mid + 1; i <= right; i++) {
            sumNow += nums[i];
            if(sumNow > sum_across) {
                sum_across = sumNow;
            }
        }
        return max(sum_left, max(sum_right, sum_across));
    }
public:
    int maxSubArray(vector<int>& nums) {
        int result, n = nums.size();
        result = helper(nums, 0, n - 1);
        return result;
    }
};

int main() {
	int n[] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> nums(n, n + 9);
	Solution s;
	cout << s.maxSubArray(nums) << endl;
	return 0;
}