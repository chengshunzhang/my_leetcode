#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int starPos = -1, sPos, sp = 0, pp = 0;
        while(sp < s.size()) {
            if(s[sp] == p[pp] || p[pp] == '?') {
                sp++;
                pp++;
            } else if(p[pp] == '*') {
                if(pp + 1 == p.size()) {
                    return true;
                }
                starPos = pp++;
                sPos = sp;
            } else if(starPos != -1) {
                pp = starPos + 1;
                sp = sPos + 1;
                sPos++;
            } else {
                return false;
            }
        }
        while(pp < p.size() && p[pp] == '*') {
            pp++;
        }
        return pp == p.size();
    }
};

int main() {
	Solution s;
	cout << s.isMatch("aa", "*") << endl;
	return 0;
}