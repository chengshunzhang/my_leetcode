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
        int buy1 = INT_MIN, buy2 = INT_MIN, sell1 = 0, sell2 = 0;
        int buy1_pre, buy2_pre, sell1_pre, sell2_pre;
        for(int i = 0; i < n; i++) {
            buy1_pre = buy1;
            buy2_pre = buy2;
            sell1_pre = sell1;
            sell2_pre = sell2;
            buy1 = max(buy1_pre, -prices[i]);
            sell1 = max(sell1_pre, prices[i] + buy1_pre);
            buy2 = max(buy2_pre, sell1_pre - prices[i]);
            sell2 = max(sell2_pre, prices[i] + buy2_pre);
        }
        return sell2;
    }
};

int main() {
	vector<int> prices = {3,3,5,0,0,3,1,4};
	Solution s;
	cout << s.maxProfit(prices) << endl;
	return 0;
}