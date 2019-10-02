#include <iostream>
using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0 || k == 0 || (k == 1 && n > 2)) {
            return 0;
        }
        if(n == 1) {
            return k;
        }
        int result = k;
        int kFork = 1;
        for(int i = 2; i < n; i++) {
            int currKFork = result - kFork;
            result += kFork * (k - 2) + currKFork * (k - 1);
            kFork = currKFork;
        }
        return result * k;
    }
};

int main() {
    int n = 3, k = 2;
    Solution sol;
    cout << sol.numWays(n, k) << endl;
    return 0;
}