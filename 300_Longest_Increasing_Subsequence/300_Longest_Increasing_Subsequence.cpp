#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++) {
            int maxL = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i] && dp[j] + 1 > maxL) {
                    maxL = dp[j] + 1;
                }
            }
            dp[i] = maxL;
        }
        int result = dp[0];
        for(int i = 1; i < nums.size(); i++) {
            if(dp[i] > result) {
                result = dp[i];
            }
        }
        return result;
    }
};

int main() {
	int n[] = {10,9,2,5,3,7,101,18};
	vector<int> nums(n,n+8);
	Solution s;
	cout << s.lengthOfLIS(nums) << endl;
	return 0;
}