#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > dp(n + 2, vector<int> (n + 2, 0));
        for(int i = 1; i <= n; i++) {
            dp[i][i] = nums[i] * nums[i - 1] * nums[i + 1];
        }
        for(int len = 2; len <= n; len++) {
            for(int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1, maxi = max(dp[i + 1][j] + nums[i] * nums[i - 1] * nums[j + 1], dp[i][j - 1] + nums[j] * nums[i - 1] * nums[j + 1]);
                for(int k = i + 1; k + 1 <= j; k++) {
                    int cur = dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1];
                    if(cur > maxi) {
                        maxi = cur;
                    }
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};

int main() {
	int n[] = {3,1,5,8};
	vector<int> nums(n,n+4);
	Solution s;
	cout << s.maxCoins(nums) << endl;
	return 0;
}