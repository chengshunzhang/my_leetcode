#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++) {
            if(m[t[i]] > 0) {
                m[t[i]]--;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
	string s("anagram"), t("naagram");
	Solution sol;
	cout << sol.isAnagram(s, t) << endl;
	return 0;
}