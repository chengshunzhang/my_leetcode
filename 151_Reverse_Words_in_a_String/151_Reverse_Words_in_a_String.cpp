#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) {
            return;
        }
        int n = s.size() - 1, last = n, i = n;
        while(i >= 0 && s[i] == ' ') {
            i--;
        }
        if(i != last) {
            s = s.substr(0, i + 1);
            last = i;
        }
        while(i >= 0) {
            while(i >= 0 && s[i] != ' ') {
                i--;
            }
            for(int j = i + 1, k = last; j < k; j++, k--) {
                char temp = s[j];
                s[j] = s[k];
                s[k] = temp;
            }
            last = i;
            while(i >= 0 && s[i] == ' ') {
                i--;
            }
            if(last > 0) {
            	s = s.substr(0, i + 1) + s.substr(last);
            	last = i;
            }
        }
        if(s[0] == ' ') {
            s = s.substr(1);
        }
        for(int j = 0, k = s.size() - 1; j < k; j++, k--) {
            char temp = s[j];
            s[j] = s[k];
            s[k] = temp;
        }
    }
};

int main() {
	Solution sol;
	string s("the sky is blue");
	sol.reverseWords(s);
	cout << s << endl;
	return 0;
}