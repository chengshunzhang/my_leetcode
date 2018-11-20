#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(coins.empty()) {
            return amount == 0;
        }
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++) {
            for(int amt = coins[i]; amt <= amount; amt++) {
                dp[amt] += dp[amt - coins[i]];
            }
        }
        return dp[amount];
    }
};

int main() {
	int amount = 5, c[] = {1,2,5};
	vector<int> coins(c,c+3);
	Solution s;
	cout << s.change(amount, coins) << endl;
	return 0;
}