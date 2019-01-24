#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 0; i + 1 < prices.size(); i++) {
            int start = i;
            while(i + 1 < prices.size() && prices[i] < prices[i + 1]) {
                i++;
            }
            if(i != start) {
                profit += prices[i] - prices[start];
            }
        }
        return profit;
    }
};

int main() {
	vector<int> prices = {7,1,5,3,6,4};
	Solution s;
	cout << s.maxProfit(prices) << endl;
	return 0;
}