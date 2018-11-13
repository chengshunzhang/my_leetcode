#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = 1, max_l = 1, n = s.size();
        if(!n) {
            return "";
        }
        string result(s,0,1);
        for(int i = 1; i < n; i++) {
            int left = i - 1, right = i;
            while(left > -1 && right < n) {
                if(s[left] == s[right]) {
                    left--;
                    right++;
                } else {
                    break;
                }
            }
            length = right - left - 1;
            if(length > max_l) {
                max_l = length;
                result.assign(s, left + 1, length);
            }
        }
        for(int i = 1; i < n - 1; i++) {
            int left = i - 1, right = i + 1;
            while(left > -1 && right < n) {
                if(s[left] == s[right]) {
                    left--;
                    right++;
                } else {
                    break;
                }
            }
            length = right - left - 1;
            if(length > max_l) {
                max_l = length;
                result.assign(s, left + 1, length);
            }
        }
        return result;
    }
};

int main() {
	string s("babad");
	Solution sol;
	cout << sol.longestPalindrome(s) << endl;
	return 0;
}