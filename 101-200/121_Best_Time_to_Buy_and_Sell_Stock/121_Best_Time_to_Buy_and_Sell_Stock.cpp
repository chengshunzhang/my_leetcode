#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() == 1) {
            return 0;
        }
        int min = INT_MAX, maxp = 0;
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < min) {
                min = prices[i];
            } else {
                if(prices[i] - min > maxp) {
                    maxp = prices[i] - min;
                }
            }
        }
        return maxp;
    }
};

int main() {
	vector<int> prices = {7,1,5,3,6,4};
	Solution s;
	cout << s.maxProfit(prices) << endl;
	return 0;
}