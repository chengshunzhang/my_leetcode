#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        return s;
    }
};

int main() {
	Solution s;
	string str("hello");
	cout << s.reverseString(str) << endl;
	return 0;
}