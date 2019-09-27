#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    enum states {
        start,
        digitBeforeExpBeforeDot,
        digitBeforeExpAfterDot,
        digitAfterExp,
        signBeforeExp,
        signAfterExp,
        exp,
        dotBeforeDigit,
        dotAfterDigit,
        end
    };
public:
    bool isNumber(string s) {
        states currState = start;
        for(int i = 0; i < s.size(); i++) {
            if(currState == start) {
                if(s[i] >= '0' && s[i] <= '9') {
                    currState = digitBeforeExpBeforeDot;
                } else if(s[i] == ' ') {
                    continue;
                } else if(s[i] == '+' || s[i] == '-') {
                    currState = signBeforeExp;
                } else if(s[i] == '.') {
                    currState = dotBeforeDigit;
                } else {
                    return false;
                }
            } else if(currState == digitBeforeExpBeforeDot) {
                if(s[i] >= '0' && s[i] <= '9') {
                    continue;
                } else if(s[i] == 'e') {
                    currState = exp;
                } else if(s[i] == '.') {
                    currState = dotAfterDigit;
                } else if (s[i] == ' ') {
                    currState = end;
                } else {
                    return false;
                }
            } else if(currState == digitBeforeExpAfterDot) {
                if(s[i] >= '0' && s[i] <= '9') {
                    continue;
                } else if(s[i] == 'e') {
                    currState = exp;
                } else if (s[i] == ' ') {
                    currState = end;
                } else {
                    return false;
                }
            } else if(currState == digitAfterExp) {
                if(s[i] >= '0' && s[i] <= '9') {
                    continue;
                } else if(s[i] == ' ') {
                    currState = end;
                } else {
                    return false;
                }
            } else if(currState == signBeforeExp) {
                if(s[i] >= '0' && s[i] <= '9') {
                    currState = digitBeforeExpBeforeDot;
                } else if(s[i] == '.') {
                    currState = dotBeforeDigit;
                } else {
                    return false;
                }
            } else if(currState == signAfterExp) {
                if(s[i] >= '0' && s[i] <= '9') {
                    currState = digitAfterExp;
                } else {
                    return false;
                }
            } else if(currState == dotBeforeDigit) {
                if(s[i] >= '0' && s[i] <= '9') {
                    currState = digitBeforeExpAfterDot;
                } else {
                    return false;
                }
            } else if(currState == dotAfterDigit) {
                if(s[i] >= '0' && s[i] <= '9') {
                    currState = digitBeforeExpAfterDot;
                } else if(s[i] == 'e') {
                    currState = exp;
                } else if(s[i] == ' ') {
                    currState = end;
                } else {
                    return false;
                }
            } else if(currState == exp) {
                if(s[i] >= '0' && s[i] <= '9') {
                    currState = digitAfterExp;
                } else if(s[i] == '+' || s[i] == '-') {
                    currState = signAfterExp;
                } else {
                    return false;
                }
            } else if(currState == end) {
                if(s[i] != ' ') {
                    return false;
                }
            }
        }
        if(currState == digitBeforeExpBeforeDot || currState == digitBeforeExpAfterDot || currState == digitAfterExp || currState == dotAfterDigit || currState == end) {
            return true;
        }
        return false;
    }
};

int main() {
    string s = ".1";
    Solution sol;
    cout << sol.isNumber(s) << endl;
    return 0;
}