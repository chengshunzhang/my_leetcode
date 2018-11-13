#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0, power = 5;
        while(n >= power) {
            result = result + n / power;
            if(power > ((uint)1 << 31) / 5) {
                break;
            } else {
                power = power * 5;
            }
        }
        return result;
    }
};

int main() {
    int n = 13;
    Solution s;
    cout << s.trailingZeroes(n) << endl;
    return 0;
}