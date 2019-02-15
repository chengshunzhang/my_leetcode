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
        int preBuy, curBuy = INT_MIN, preSell = 0, curSell = 0;
        for(int i = 0; i < n; i++) {
            preBuy = curBuy;
            curBuy = max(preBuy, preSell - prices[i]);
            preSell = curSell;
            curSell = max(preSell, preBuy + prices[i]);
        }
        return curSell;
    }
};

int main() {
    Solution s;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << s.maxProfit(prices) << endl;
    return 0;
}