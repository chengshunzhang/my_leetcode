#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sh[256] = {0}, th[256] = {0};
        for(int i = 0; i < s.size(); i++) {
            if(sh[s[i]] == th[t[i]]) {
                sh[s[i]] = i + 1;
                th[t[i]] = i + 1;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
	Solution sol;
	string s("ab"), t("aa");
	cout << sol.isIsomorphic(s, t) << endl;
	return 0;
}