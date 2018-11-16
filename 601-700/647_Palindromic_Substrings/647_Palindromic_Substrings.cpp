#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), result = n;
        vector<vector<bool> > dp(n, vector<bool> (n, false));
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for(int i = 0; i + 1 < n; i++) {
            if(s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                result++;
            }
        }
        for(int j = 2; j < n; j++) {
            for(int i = 0; i < j - 1; i++) {
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    result++;
                }
            }
        }
        return result;
    }
};

int main() {
	Solution s;
	string str("aaa");
	cout << s.countSubstrings(str) << endl;
	return 0;
}