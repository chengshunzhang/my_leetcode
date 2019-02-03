#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0, curLen = 0, start = 0, pos;
        unordered_map<char, int> hash;
        for(int i = 0; i < s.size(); i++) {
            if(hash.count(s[i]) && (pos = hash[s[i]]) >= start) {
                if(result < curLen) {
                    result = curLen;
                }
                curLen = curLen - (pos - start) - 1;
                start = pos + 1;
            }
            hash[s[i]] = i;
            curLen++;
        }
        return max(result, curLen);
    }
};

int main() {
    Solution s;
    string str("abcabcbb");
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}