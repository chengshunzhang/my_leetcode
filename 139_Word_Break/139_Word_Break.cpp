#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size());
        unordered_map<string, bool> hash;
        int maxL = 0;
        for(int i = 0; i < wordDict.size(); i++) {
            hash[wordDict[i]] = true;
            if(wordDict[i].size() > maxL) {
                maxL = wordDict[i].size();
            }
        }
        for(int i = 0; i < s.size(); i++) {
            if(hash.count(s.substr(0, i + 1))) {
                dp[i] = true;
            } else {
                for(int j = max(0, i - maxL); j < i; j++) {
                    if(dp[j] && hash.count(s.substr(j + 1, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size() - 1];
    }
};

int main() {
	string str("leetcode");
	vector<string> words;
	words.push_back("leet");
	words.push_back("code");
	Solution s;
	cout << s.wordBreak(str, words) << endl;
	return 0;
}