#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) {
            return s.empty();
        }
        vector<vector<bool>> dp(s.size() + 1, vector<bool> (p.size() + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= s.size(); i++) {
            for(int j = 1; j <= p.size(); j++) {
                dp[i][j] = (i > 0 && j > 1 && dp[i - 1][j] && p[j - 1] == '*' && (p[j - 2] == s[i - 1] || p[j - 2] == '.')) ||
                (i > 0 && dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.')) ||
                (j > 1 && dp[i][j - 2] && p[j - 1] == '*');
            }
        }
        return dp[s.size()][p.size()];
    }
};

int main() {
	string s = "mississippi", p = "mis*is*p*.";
	Solution sol;
	cout << sol.isMatch(s, p) << endl;
	return 0;
}