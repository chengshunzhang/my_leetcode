#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1) {
            return 1;
        }
        if(x == -1) {
            return n % 2 == 0 ? 1 : -1;
        }
        if(n == (1 << 31) || x == 0) {
            return 0;
        }
        double result = 1;
        bool neg = false;
        if(n < 0) {
            n = -n;
            neg = true;
        }
        while(n) {
            if(n & 1) {
                result *= x;
            }
            x *= x;
            n = n >> 1;
        }
        return neg ? 1 / result : result;
    }
};

int main() {
	Solution s;
	cout << s.myPow(2, -((1 << 31) + 1)) << endl;
	return 0;
}