#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int lastIn, lastNotIn, n = nums.size();
        if(n == 0) {
            return 0;
        }
        if(n == 1) {
            return nums[0];
        }
        if(n == 2) {
            return max(nums[0], nums[1]);
        }
        if(n == 3) {
            return max(nums[0], max(nums[1], nums[2]));
        }
        vector<int> lastInA(n - 2);
        lastInA[0] = 0;
        lastInA[1] = nums[1];
        for(int i = 2; i < n - 2; i++) {
            int first = lastInA[i - 2] + nums[i], second = lastInA[i - 1];
            lastInA[i] = max(first, second);
        }
        lastIn = lastInA[n - 3] + nums[n - 1];
        vector<int> lastNotInA(n);
        lastNotInA[0] = 0;
        lastNotInA[1] = nums[0];
        for(int i = 2; i < n; i++) {
            int first = lastNotInA[i - 2] + nums[i - 1], second = lastNotInA[i - 1];
            lastNotInA[i] = max(first, second);
        }
        lastNotIn = lastNotInA[n - 1];
        return max(lastIn, lastNotIn);
    }
};

int main() {
	int n[] = {2,2,3};
	vector<int> nums(n,n+3);
	Solution s;
	cout << s.rob(nums) << endl;
	return 0;
}