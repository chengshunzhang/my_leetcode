#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) {
            return s.empty();
        }
        if(p.size() > 1 && p[1] == '*') {
            return (isMatch(s, p.substr(2))) ||
                (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        } else {
            return (!s.empty() && (s[0] == p[0] || p[0] == '.') &&
                    isMatch(s.substr(1), p.substr(1)));
        }
    }
};

int main() {
    Solution s;
    string s1("ab"), s2(".*c");
    cout << s.isMatch(s1, s2) << endl;
    return 0;
}