#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 32; i++) {
            if((1 << i) & n) {
                result = result + (1 << (31 - i));
            }
        }
        return result;
    }
};

int main() {
	uint32_t a = 43261596;
	Solution s;
	cout << s.reverseBits(a) << endl;
	return 0;
}