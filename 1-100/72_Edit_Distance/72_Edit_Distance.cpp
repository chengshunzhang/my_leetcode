#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1 == word2) {
            return 0;
        }
        int m = word1.size(), n = word2.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        for(int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for(int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                int choice1 = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]) + 1, choice1);
            }
        }
        return dp[m][n];
    }
};

int main() {
	string word1("horse"), word2("ros");
	Solution s;
	cout << s.minDistance(word1, word2) << endl;
	return 0;
}