#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1));
        dp[0][0] = 1;
        for(int j = 1; j <= n; j++) {
            dp[0][j] = 0;
        }
        for(int i = 1; i <= m; i++) {
            if(p[i - 1] != '*') {
                for(int row = i; row <= m; row++) {
                    dp[row][0] = -1;
                }
                break;
            } else {
                dp[i][0] = 1;
            }
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[j - 1] == p[i - 1] || p[i - 1] == '?') {
                    if(dp[i - 1][j - 1] == 1) {
                        dp[i][j] = 1; // first i elements in p matches first j elements in s
                    } else if(dp[i][j - 1] != -1){
                        dp[i][j] = 0; // first i elements in p does not match first j elements in s, but first i elements
                    } else {          // in p matches a substring of first j elements in s
                        dp[i][j] = -1;
                    }
                } else if(p[i - 1] == '*') {
                    if(dp[i - 1][j] != -1) {
                        dp[i][j] = 1;
                    } else if(dp[i][j - 1] != -1){
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = -1;
                    }
                } else {
                    if(dp[i][j - 1] != -1) {
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = -1;
                    }
                }
            }
        }
        return dp[m][n] == 1;
    }
};

int main() {
	Solution s;
	cout << s.isMatch("aa", "*") << endl;
    string str("abc");
    cout << str[3] << endl;
	return 0;
}