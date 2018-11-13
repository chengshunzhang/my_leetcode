#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    bool helper(string s, char thisParenthesis) {
       int numThis = 0, numAnother = 0, star = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == thisParenthesis) {
                numThis++;
            } else if(s[i] == '*') {
                star++;
            } else {
                numAnother++;
            }
            if(numAnother > numThis + star) {
                return false;
            } else if(numAnother > numThis){
                star -= numAnother - numThis;
                numAnother = numThis = 0;
            }
        }
        return true;
    }
public:
    bool checkValidString(string s) {
        if(helper(s, '(')) {
            reverse(s.begin(), s.end());
            return helper(s, ')');
        } else {
            return false;
        }
    }
};

int main() {
	string str("()");
	Solution s;
	cout << s.checkValidString(str) << endl;
	return 0;
}