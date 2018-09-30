#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        unsigned long product;
        while(left + 1 < right) {
            unsigned long mid = left + (right - left) / 2;
            product = mid * mid;
            if(product == x) {
                return mid;
            } else if(product > x) {
                right = mid;
            } else {
                left = mid;
            }
        }
        product = right * right;
        if(product <= x) {
            return right;
        } else {
            return left;
        }
    }
};

int main() {
	int x = 183692038;
	Solution s;
	cout << s.mySqrt(x) << endl;
	return 0;
}