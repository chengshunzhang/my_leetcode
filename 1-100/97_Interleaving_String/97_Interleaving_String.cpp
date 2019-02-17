#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if(m + n != s3.size()) {
            return false;
        }
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++) {
            if(dp[0][i - 1] && s2[i - 1] == s3[i - 1]) {
                dp[0][i] = true;
            }
        }
        for(int i = 1; i <= m; i++) {
            if(dp[i - 1][0] && s1[i - 1] == s3[i - 1]) {
                dp[i][0] = true;
            }
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if((dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                  (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
	Solution s;
	string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
	cout << s.isInterleave(s1, s2, s3) << endl;
	return 0;
}