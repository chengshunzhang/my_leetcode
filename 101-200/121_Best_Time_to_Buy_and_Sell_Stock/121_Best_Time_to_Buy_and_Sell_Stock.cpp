#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n == 1) {
            return 0;
        }
        int A[n], min;
        A[0] = 0;
        int temp = prices[1] - prices[0];
        if(temp > 0) {
            A[1] = temp;
            min = prices[0];
        } else {
            A[1] = 0;
            min = prices[1];
        }
        for(int i = 2; i < n; i++) {
            temp = prices[i] - min;
            A[i] = temp > A[i - 1] ? temp : A[i - 1];
            if(prices[i] < min) {
                min = prices[i];
            }
        }
        return A[n - 1];
    }
};

int main() {
	int n[] = {7,1,5,3,6,4};
	vector<int> prices(n, n + 6);
	Solution s;
	cout << s.maxProfit(prices) << endl;
	return 0;
}