#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        while(sum != 1) {
            sum = 0;
            while(n > 0) {
                int digit = n % 10;
                sum = sum + digit * digit;
                n = n / 10;
            }
            if(sum == 4) {
                return false;
            }
            n = sum;
        }
        return true;
    }
};

int main() {
	Solution s;
	cout << s.isHappy(2) << endl;
	return 0;
}