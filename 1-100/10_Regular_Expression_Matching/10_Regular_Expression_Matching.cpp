#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.size(), p_len = p.size();
        if(!s_len && !p_len){
            return true;
        }
        if(!p_len && s_len) {
            return false;
        }
        if(!s_len) {
            int p_pos = 0;
            while(p_pos + 1 < p_len && p[p_pos + 1] == '*') {
                p_pos += 2;
            }
            if(p_pos == p_len) {
                return true;
            } else {
                return false;
            }
        }
        if(p[0] != s[0]) {
            if(p[0] == '.') {
                if(p_len == 1 || p[1] != '*') {
                    return isMatch(s.substr(1), p.substr(1));
                } else {
                    for(int i = 0; i <= s_len; i++) {
                        if(isMatch(s.substr(i), p.substr(2))) {
                            return true;
                        }
                    }
                    return false;
                }
            } else if(p_len > 1 && p[1] == '*'){
                return isMatch(s, p.substr(2));
            } else {
                return false;
            }
        } else {
            if(p_len == 1 || p[1] != '*') {
                return isMatch(s.substr(1), p.substr(1));
            } else {
                int count = 1;
                for(int i = 1; i < s_len && s[i] == s[0]; i++) {
                    count++;
                }
                for(int i = 0; i <= count; i++) {
                    if(isMatch(s.substr(i), p.substr(2))) {
                        return true;
                    }
                }
                return false;
            }
        }
    }
};

int main() {
    Solution s;
    string s1("ab"), s2(".*c");
    cout << s.isMatch(s1, s2) << endl;
    return 0;
}