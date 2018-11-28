#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    void helper(string& s, vector<vector<string> >& result, vector<string>& temp, int pos, vector<vector<bool> >& isPalindrome) {
        if(pos == s.size()) {
            result.push_back(temp);
        }
        for(int i = pos; i< s.size(); i++) {
            if(isPalindrome[pos][i]) {
                temp.push_back(s.substr(pos, i - pos + 1));
                helper(s, result, temp, i + 1, isPalindrome);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string> > partition(string s) {
        int n = s.size();
        vector<vector<bool> > isPalindrome(n, vector<bool> (n, false));
        for(int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }
        for(int i = 0; i + 1 < n; i++) {
            if(s[i] == s[i + 1]) {
                isPalindrome[i][i + 1] = true;
            }
        }
        for(int len = 2; len < n; len++) {
            for(int i = 0; i + len < n; i++) {
                int j = i + len;
                if(isPalindrome[i + 1][j - 1] && s[i] == s[j]) {
                    isPalindrome[i][j] = true;
                }
            }
        }
        vector<vector<string> > result;
        vector<string> temp;
        helper(s, result, temp, 0, isPalindrome);
        return result;
    }
};

int main() {
	string str("aab");
	Solution s;
	vector<vector<string> > res = s.partition(str);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ',';
		}
		cout << "\b \b" << endl;
	}
	return 0;
}