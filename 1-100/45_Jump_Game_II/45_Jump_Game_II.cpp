#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty()) {
            return -1;
        }
        if(nums.size() == 1) {
            return 0;
        }
        vector<int> dp(nums.size(), -1);
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++) {
            int right = i + nums[i];
            if(right >= nums.size() - 1) {
                return dp[i] + 1;
            }
            for(int j = right; j > i && dp[j] == -1; j--) {
                dp[j] = dp[i] + 1;
            }
        }
        return -1;
    }
};

int main() {
	int n[] = {2,3,1,1,4};
	vector<int> nums(n,n+5);
	Solution s;
	cout << s.jump(nums) << endl;
	return 0;
}