#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.empty()) {
            return t.size() == 1;
        }
        int n = s.size(), m = t.size();
        bool diff = false;
        if(n - m == -1) {
            int sp = 0, tp = 0;
            while(sp < n) {
                if(s[sp] != t[tp]) {
                    if(diff) {
                        return false;
                    } else {
                        diff = true;
                    }
                } else {
                    sp++;
                }
                tp++;
            }
            return true;
        } else if(n == m) {
            for(int i = 0; i < n; i++) {
                if(s[i] != t[i]) {
                    if(!diff) {
                        diff = true;
                    } else {
                        return false;
                    }
                }
            }
            return diff;
        } else if(n - m == 1) {
            return isOneEditDistance(t, s);
        }
        return false;
    }
};

int main() {
    string s = "ab", t = "acb";
    Solution sol;
    cout << sol.isOneEditDistance(s, t) << endl;
    return 0;
}