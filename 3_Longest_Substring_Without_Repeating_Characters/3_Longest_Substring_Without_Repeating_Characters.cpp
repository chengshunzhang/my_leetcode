#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0, temp = 0, start = 0, re_pos;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++) {
            if(m.count(s[i]) && (re_pos = m.find(s[i]) -> second) >= start) {
                if(result < temp) {
                    result = temp;
                }
                temp = temp - (re_pos - start) - 1;
                start = re_pos + 1;
            }
            m[s[i]] = i;
            temp++;
        }
        if(result < temp) {
            result = temp;
        }
        return result;
    }
};

int main() {
    Solution s;
    string str("abcabcbb");
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}