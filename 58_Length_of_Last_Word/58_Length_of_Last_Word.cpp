#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastSpacePos = -1, n = s.size(), len = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                lastSpacePos = i;
            }
        }
        if(lastSpacePos < n - 1) {
            for(int i = lastSpacePos + 1; i < n; i++) {
                len++;
            }
        } else if(lastSpacePos > 0){
            int p = lastSpacePos - 1;
            while(p > -1 && s[p] == ' ') {
                p--;
            }
            while(p > -1 && s[p] != ' ') {
                p--;
                len++;
            }
        }
        return len;
    }
};

int main() {
	Solution s;
	string str("Hello World");
	cout << s.lengthOfLastWord(str) << endl;
	return 0;
}