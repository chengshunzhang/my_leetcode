#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0) {
            return 0;
        }
        if(m == n) {
            return m;
        }
        int mH = -1, nH = -1;
        for(int i = 0; i < 31 && (1 << i) <= m; i++) {
            if((1 << i) & m) {
                mH = i;
            }
        }
        for(int i = 0; i < 31 && (1 << i) <= n; i++) {
            if((1 << i) & n) {
                nH = i;
            }
        }
        if(nH > mH) {
            return 0;
        } else {
            int result = (1 << nH);
            while(((1 << --nH) & n) == ((1 << --mH) & m)) {
                result += ((1 << nH) & n);
            }
            return result;
        }
    }
};

int main() {
	int m = 6, n = 8;
	Solution s;
	cout << s.rangeBitwiseAnd(m, n) << endl;
	return 0;
}