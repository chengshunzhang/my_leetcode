#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) {
            return true;
        }
        string sProcessed;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                sProcessed.push_back(s[i] - 'A' + 'a');
            } else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                sProcessed.push_back(s[i]);
            }
        }
        for(int i = 0, j = sProcessed.size() - 1; i < j; i++, j--) {
            if(sProcessed[i] != sProcessed[j]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
	string str("A man, a plan, a canal; Panama");
	Solution s;
	cout << s.isPalindrome(str) << endl;
	return 0;
}