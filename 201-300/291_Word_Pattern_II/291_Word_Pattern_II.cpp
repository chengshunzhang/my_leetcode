#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
private:
    bool helper(string& pattern, string& str, vector<string>& letters, unordered_set<string>& used, int p, int s) {
        if(p == pattern.size()) {
            return s == str.size();
        }
        int curr = pattern[p] - 'a';
        string projection = letters[curr];
        if(projection == "") {
            for(int len = 1; s + len <= str.size(); len++) {
                string temp = str.substr(s, len);
                if(used.find(temp) != used.end()) {
                    continue;
                }
                letters[curr] = temp;
                used.insert(temp);
                if(helper(pattern, str, letters, used, p + 1, s + len)) {
                    return true;
                }
                used.erase(temp);
            }
            letters[curr] = "";
            return false;
        } else {
            int len = projection.size();
            if(projection == str.substr(s, len)) {
                return helper(pattern, str, letters, used, p + 1, s + len);
            } else {
                return false;
            }
        }
    }
public:
    bool wordPatternMatch(string pattern, string str) {
        vector<string> letters(26, "");
        unordered_set<string> used;
        return helper(pattern, str, letters, used, 0, 0);
    }
};

int main() {
	string pattern = "abba", str = "dogcatcatdog";
	Solution sol;
	cout << sol.wordPatternMatch(pattern, str) << endl;
	return 0;
}