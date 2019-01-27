#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.empty() || k == 0) {
            return 0;
        }
        vector<int> chars(260, 0);
        int left = 0, right = 0, maxLen = 0, numDist = 0;
        while(right < s.size()) {
            chars[s[right]]++;
            if(chars[s[right]] == 1) {
                numDist++;
            }
            while(numDist > k) {
                chars[s[left]]--;
                if(chars[s[left]] == 0) {
                    numDist--;
                }
                left++;
            }
            int curLen = right - left + 1;
            if(curLen > maxLen) {
                maxLen = curLen;
            }
            right++;
        }
        return maxLen;
    }
};

int main() {
	Solution sol;
	string s = "eceba";
	int k = 2;
	cout << sol.lengthOfLongestSubstringKDistinct(s, k) << endl;
	return 0;
}