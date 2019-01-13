#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    bool isUpper(char c) {
        return c >= 'A' && c <= 'Z';
    }
    
    void toLower(char& c) {
        c = c - 'A' + 'a';
    }
    
    string maskEmail(string S, int pos) {
        string result;
        if(isUpper(S[0])) {
            toLower(S[0]);
        }
        result.push_back(S[0]);
        for(int i = 0; i < 5; i++) {
            result.push_back('*');
        }
        if(isUpper(S[pos - 1])) {
            toLower(S[pos - 1]);
        }
        result.push_back(S[pos - 1]);
        for(int i = pos; i < S.size(); i++) {
            if(isUpper(S[i])) {
                toLower(S[i]);
            }
            result.push_back(S[i]);
        }
        return result;
    }
    
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    
    string maskPhone(string S) {
        string result;
        int digits = 0;
        for(int i = S.size() - 1; i >= 0; i--) {
            if(isDigit(S[i])) {
                digits++;
                if(digits <= 4) {
                    result.push_back(S[i]);   
                } else if(digits == 5 || digits == 8 || digits == 11) {
                    result.push_back('-');
                    result.push_back('*');
                } else {
                    result.push_back('*');
                }
            }
        }
        if(digits > 10) {
            result.push_back('+');
        }
        reverse(result.begin(), result.end());
        return result;
    }
public:
    string maskPII(string S) {
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '@') {
                return maskEmail(S, i);
            }
        }
        return maskPhone(S);
    }
};

int main() {
	Solution s;
	string S = "LeetCode@LeetCode.com";
	cout << s.maskPII(S) << endl;
	return 0;
}