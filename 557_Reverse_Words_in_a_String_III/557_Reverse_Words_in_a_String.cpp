#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result(s);
        int start = 0;
        for(int i = 0; i < s.size(); i++) {
            while(i < s.size() && s[i] != ' ') {
                i++;
            }
            for(int j = i - 1; start < j; start++, j--) {
                char temp = result[start];
                result[start] = result[j];
                result[j] = temp;
            }
            start = i + 1;
        }
        return result;
    }
};

int main() {
	string str("Let's take Leetcode contest");
	Solution s;
	cout << s.reverseWords(str) << endl;
	return 0;
}