#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    int calculateLen(string& s, string parentheses) {
        int maxLen = 0, currLen = 0, left = 0, num = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == parentheses[0]) {
                num++;
            } else if(num > 0) {
                num--;
            } else {
                currLen = i - left;
                if(currLen > maxLen) {
                    maxLen = currLen;
                }
                left = i + 1;
            }
        }
        if(num == 0) {
            currLen = s.size() - left;
            if(currLen > maxLen) {
                maxLen = currLen;
            }
        }
        s = s.substr(left);
        return maxLen;
    }
    
public:
    int longestValidParentheses(string s) {
        int forward = calculateLen(s, "()");
        reverse(s.begin(), s.end());
        int backward = calculateLen(s, ")(");
        return max(forward, backward);
    }
};

int main() {
    string s = "(()";
    Solution sol;
    cout << sol.longestValidParentheses(s) << endl;
    return 0;
}