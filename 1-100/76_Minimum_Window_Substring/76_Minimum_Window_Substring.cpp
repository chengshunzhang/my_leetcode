#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, start = 0, count = 0, minLen = INT_MAX;
        string result = "";
        vector<int> chars(256, 0);
        for(int i = 0; i < t.size(); i++) {
            chars[t[i]]++;
        }
        for(int i = 0; i < s.size(); i++) {
            chars[s[i]]--;
            if(chars[s[i]] >= 0) {
                count++;
            }
            while(count == t.size()) {
                int curLen = i - left + 1;
                if(curLen < minLen) {
                    minLen = curLen;
                    start = left;
                }
                chars[s[left]]++;
                if(chars[s[left]] > 0) {
                    count--;
                }
                left++;
            }
        }
        if(minLen == INT_MAX) {
            return "";
        }
        return s.substr(start, minLen);
    }
};

int main() {
	string S = "ADOBECODEBANC", T = "ABC";
	Solution s;
	cout << s.minWindow(S, T) << endl;
	return 0;
}