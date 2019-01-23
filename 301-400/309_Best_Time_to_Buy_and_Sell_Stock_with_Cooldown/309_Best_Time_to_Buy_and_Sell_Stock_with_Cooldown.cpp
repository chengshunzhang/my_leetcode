#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() == 1) {
            return 0;
        }
        int n = prices.size();
        vector<int> buy(n), sell(n);
        buy[0] = -prices[0];
        buy[1] = max(-prices[0], -prices[1]);
        sell[0] = 0;
        sell[1] = max(0, buy[0] + prices[1]);
        for(int i = 2; i < n; i++) {
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return sell[n - 1];
    }
};

int main() {
	Solution s;
	vector<int> prices = {1, 2, 3, 0, 2};
	cout << s.maxProfit(prices) << endl;
	return 0;
}