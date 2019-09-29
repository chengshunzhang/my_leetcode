#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int n = s.size();
        vector<int> chars(256, 0);
        int odd = 0;
        for(int i = 0; i < n; i++) {
            chars[s[i]]++;
        }
        for(int i = 0; i < 256; i++) {
            if(chars[i] % 2 == 1) {
                odd++;
            }
            if(odd > 1) {
                return false;
            }
        }
        return (n % 2 == 0 && odd == 0) || (n % 2 == 1 && odd == 1);
    }
};

int main() {
    string s = "code";
    Solution sol;
    cout << sol.canPermutePalindrome(s) << endl;
    return 0;
}