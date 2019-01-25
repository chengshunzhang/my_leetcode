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
        vector<vector<int>> buy(2, vector<int>(n, 0));
        vector<vector<int>> sell(2, vector<int>(n, 0));
        buy[0][0] = buy[1][0] = -prices[0];
        sell[0][0] = sell[1][0] = 0;
        for(int i = 1; i < n; i++) {
            buy[0][i] = max(buy[0][i - 1], -prices[i]);
            sell[0][i] = max(sell[0][i - 1], prices[i] + buy[0][i - 1]);
            buy[1][i] = max(buy[1][i - 1], sell[0][i - 1] - prices[i]);
            sell[1][i] = max(sell[1][i - 1], prices[i] + buy[1][i - 1]);
        }
        return sell[1][n - 1];
    }
};

int main() {
	vector<int> prices = {3,3,5,0,0,3,1,4};
	Solution s;
	cout << s.maxProfit(prices) << endl;
	return 0;
}