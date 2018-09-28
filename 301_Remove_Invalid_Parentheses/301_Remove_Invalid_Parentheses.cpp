#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void removeHelper(string s, vector<string>& res, string ch, int last_pos, int last_del) {
        int count = 0;
        for(int i = last_pos; i < s.size(); i++) {
            if(s[i] == ch[0]) {
                count++;
            } else if(s[i] == ch[1]) {
                count--;
            }
            if(count >= 0) {
                continue;
            } else {
                for(int j = last_del; j <= i; j++) {
                    if(s[j] == ch[1] && ((j > last_del && s[j - 1] != ch[1]) || j == last_del)) {
                    removeHelper(s.substr(0, j) + s.substr(j + 1), res, ch, i, j);
                    }
                }
                return;
            }
        }
        string s_rev(s);
        for(int i = s.size() - 1, j = 0; i >= 0; i--) {
            s_rev[j++] = s[i];
        }
        if(ch[0] == '(') {
            removeHelper(s_rev, res, ")(", 0, 0);
        } else {
            res.push_back(s_rev);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        removeHelper(s, result, "()", 0, 0);
        return result;
    }
};

int main() {
	Solution s;
	vector<string> res = s.removeInvalidParentheses("()())()");
	for(int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}