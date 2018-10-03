#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, i = 1, n = prices.size();
        while(i < n) {
            while(i < n && prices[i] <= prices[i - 1]) {
                i++;
            }
            if(i == n) {
                break;
            } else {
                int buy = i - 1;
                while(i < n && prices[i] >= prices[i - 1]) {
                    i++;
                }
                int sell = i - 1;
                profit += prices[sell] - prices[buy];
            }
        }
        return profit;
    }
};

int main() {
	int n[] = {7,1,5,3,6,4};
	vector<int> prices(n, n + 6);
	Solution s;
	cout << s.maxProfit(prices) << endl;
	return 0;
}