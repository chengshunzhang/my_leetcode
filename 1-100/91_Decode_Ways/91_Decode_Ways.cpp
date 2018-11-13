#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(!n || s[0] == '0') {
            return 0;
        }
        if(n == 1) {
            return s[0] == '0' ? 0 : 1;
        }
        int A[n + 1];
        A[0] = 1, A[1] = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == '0') {
                if(s[i - 1] == '0' || s[i - 1] - '0' > 2) {
                    return 0;
                }
                A[i + 1] = A[i - 1];
            } else if(s[i - 1] != '0' && atoi(s.substr(i - 1, 2).c_str()) <= 26) {
                A[i + 1] = A[i] + A[i - 1];
            } else {
                A[i + 1] = A[i];
            }
        }
        return A[n];
    }
};

int main() {
	Solution s;
	string str("123");
	cout << s.numDecodings(str) << endl;
	return 0;
}