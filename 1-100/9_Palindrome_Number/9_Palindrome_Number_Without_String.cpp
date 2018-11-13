#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || ( x > 0 && x % 10 == 0)) {
            return false;
        } else {
            int xR = 0;
            while(x > xR) {
                xR = xR * 10 + x % 10;
                x /= 10;
            }
            return xR == x || xR / 10 == x;
        }
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(88) << endl;
    return 0;
}