#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        dp[0] = dp[1] = 0;
        for(int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        return dp[cost.size()];
    }
};

int main() {
	int n[] = {10,15,20};
	vector<int> cost(n,n+3);
	Solution s;
	cout << s.minCostClimbingStairs(cost) << endl;
	return 0;
}