#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) {
            return 0;
        }
        int sum = 0;
        bool negative = x < 0 ? true : false;
        if(negative) {
            x = -x;
        }
        while(x > 0) {
            if(sum != 0 && INT_MAX / sum < 10) {
                return 0;
            }
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return negative ? -sum : sum;
    }
};

int main() {
	Solution s;
	int x = -2147483648;
	cout << s.reverse(x) << endl;
	return 0;
}