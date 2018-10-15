#include <iostream>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if(n < 1) {
            return 0;
        }
        int result = 0, mul = 1, temp = 0;
        while(n > 0) {
            int digit = n % 10;
            n = n / 10;
            temp = temp + digit * mul;
            if(digit > 1) {
                result = result + (n + 1) * mul;
            } else if(digit == 1) {
                result = result + n * mul + temp - mul + 1;
            } else {
                result = result + n * mul;
            }
            mul = mul * 10;
        }
        return result;
    }
};

int main() {
	Solution s;
	cout << s.countDigitOne(13) << endl;
	return 0;
}