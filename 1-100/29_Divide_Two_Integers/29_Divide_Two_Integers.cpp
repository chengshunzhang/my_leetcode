#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1) {
            return dividend;
        }
        if(divisor == -1) {
            if(dividend == INT_MIN) {
                return INT_MAX;
            } else {
                return -dividend;
            }
        }
        long dividendp = dividend, divisorp = divisor;
        dividendp = abs(dividendp);
        divisorp = abs(divisorp);
        bool neg = ((dividend >> 31) & 1) ^ ((divisor >> 31) & 1);
        int result = 0;
        while(dividendp > 0) {
            int i = 0;
            while((divisorp << i) <= dividendp) {
                i++;
            }
            if(i == 0) {
                break;
            }
            dividendp -= (divisorp << (i - 1));
            result += (1 << (i - 1));
        }
        return neg ? -result : result;
    }
};

int main() {
	Solution s;
	int dividend = 10, divisor = 3;
	cout << s.divide(dividend, divisor) << endl;
	return 0;
}