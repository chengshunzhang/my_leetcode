#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for(int i = 1; i * i <= n; i++) {
            nums.push_back(i * i);
        }
        if(nums.back() == n) {
            return 1;
        }
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            int least = INT_MAX;
            for(int j = 0; j < nums.size() && nums[j] <= i; j++) {
                if(dp[i - nums[j]] < least) {
                    least = dp[i - nums[j]];
                }
            }
            dp[i] = least + 1;
        }
        return dp[n];
    }
};

int main() {
	int n = 12;
	Solution s;
	cout << s.numSquares(n) << endl;
	return 0;
}