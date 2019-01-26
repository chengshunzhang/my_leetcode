#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) {
            return "";
        }
        int inputLen = s.length(), start = 0, maxLen = 1;
        vector<vector<bool>> isPalindrome(inputLen, vector<bool> (inputLen, false));
        for(int i = 0; i < inputLen; i++) {
            isPalindrome[i][i] = true;
        }
        for(int i = 0; i + 1 < inputLen; i++) {
            if(s[i] == s[i + 1]) {
                isPalindrome[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }
        for(int len = 3; len <= inputLen; len++) {
            for(int i = 0; i + len - 1 < inputLen; i++) {
                int j = i + len - 1;
                if(s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                    isPalindrome[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main() {
	string input = "ccc";
	Solution s;
	cout << s.longestPalindrome(input) << endl;
	return 0;
}