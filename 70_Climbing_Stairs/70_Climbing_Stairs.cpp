#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int A[n + 1];
        A[0] = A[1] = 1;
        for(int i = 2; i <= n; i++) {
            A[i] = A[i - 1] + A[i - 2];
        }
        return A[n];
    }
};

int main() {
	Solution s;
	cout << s.climbStairs(3) << endl;
	return 0;
}