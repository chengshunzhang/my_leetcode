#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    string getPrefix(string& s1, string& s2) {
        int i = 0, j = 0;
        while(i < s1.size() && j < s2.size() && s1[i] == s2[i]) {
            i++;
            j++;
        }
        return s1.substr(0, i);
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        if(strs.size() == 1) {
            return strs[0];
        }
        string prefix = getPrefix(strs[0], strs[1]);
        if(prefix == "") {
            return "";
        }
        for(int i = 2; i < strs.size(); i++) {
            prefix = getPrefix(prefix, strs[i]);
            if(prefix == "") {
                return "";
            }
        }
        return prefix;
    }
};

int main() {
	Solution s;
	vector<string> strs = {"flower","flow","flight"};
	cout << s.longestCommonPrefix(strs) << endl;
	return 0;
}