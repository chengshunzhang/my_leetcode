#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
    private:
    void construct(string& s, vector<string>& result, string& temp, vector<vector<int> >& dp, int cur) {
        if(cur == 0) {
            result.push_back(temp);
            return;
        }
        for(int i = 1; i < dp[cur].size(); i++) {
            int pre = dp[cur][i], len = cur - dp[cur][i];
            temp = s.substr(pre, len) + " " + temp;
            construct(s, result, temp, dp, pre);
            temp = temp.substr(len + 1);
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        unordered_map<string, bool> hash;
        int maxLength = 0;
        for(int i = 0; i < wordDict.size(); i++) {
            hash[wordDict[i]] = true;
            if(wordDict[i].size() > maxLength) {
                maxLength = wordDict[i].size();
            }
        }
        vector<vector<int> > dp(s.size() + 1, vector<int> (1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= s.size(); i++) {
            for(int j = max(0, i - maxLength); j < i; j++) {
                if(dp[j][0] && hash.count(s.substr(j, i - j))) {
                    dp[i][0] = 1;
                    dp[i].push_back(j);
                }
            }
        }
        if(dp[s.size()][0] == 1) {
            for(int i = 1; i < dp[s.size()].size(); i++) {
                string temp = s.substr(dp[s.size()][i], s.size() - dp[s.size()][i]);
                construct(s, result, temp, dp, dp[s.size()][i]);
            }
        }
        return result;
    }
};

int main() {
	Solution sol;
	string s = "catsanddog";
	vector<string> words;
	words.push_back("cat");
	words.push_back("cats");
	words.push_back("and");
	words.push_back("sand");
	words.push_back("dog");
	vector<string> res = sol.wordBreak(s, words);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}