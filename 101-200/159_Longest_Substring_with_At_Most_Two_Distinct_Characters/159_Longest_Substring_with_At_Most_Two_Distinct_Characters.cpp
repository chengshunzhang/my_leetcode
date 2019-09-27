#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int maxLen = 0, currLen = 0, left = 0, n = s.size(), size = 0;
        vector<int> chars(256, 0);
        for(int i = 0; i < n; i++) {
            if(chars[s[i]] == 0) {
                if(size == 2) {
                    currLen = i - left;
                    if(currLen > maxLen) {
                        maxLen = currLen;
                    }
                    while(size == 2) {
                        chars[s[left]]--;
                        if(chars[s[left]] == 0) {
                            size--;
                        }
                        left++;
                    }
                }
                size++;
            }
            chars[s[i]]++;
        }
        return max(maxLen, n - left);
    }
};

int main() {
    string s = "eceba";
    Solution sol;
    cout << sol.lengthOfLongestSubstringTwoDistinct(s) << endl;
    return 0;
}