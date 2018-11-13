#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0, i;
        for(i = s.size() - 1; i > 0; i--) {
            if(s[i] == 'I') {
                result++;
            } else if(s[i] == 'V' && s[i - 1] != 'I') {
                result += 5;
            } else if(s[i] == 'V' && s[i - 1] == 'I') {
                result += 4;
                i--;
            } else if(s[i] == 'X' && s[i - 1] != 'I') {
                result += 10;
            } else if(s[i] == 'X' && s[i - 1] == 'I') {
                result += 9;
                i--;
            } else if(s[i] == 'L' && s[i - 1] != 'X') {
                result += 50;
            } else if(s[i] == 'L' && s[i - 1] == 'X') {
                result += 40;
                i--;
            } else if(s[i] == 'C' && s[i - 1] != 'X') {
                result += 100;
            } else if(s[i] == 'C' && s[i - 1] == 'X') {
                result += 90;
                i--;
            } else if(s[i] == 'D' && s[i - 1] != 'C') {
                result += 500;
            } else if(s[i] == 'D' && s[i - 1] == 'C') {
                result += 400;
                i--;
            } else if(s[i] == 'M' && s[i - 1] != 'C') {
                result += 1000;
            } else {
                result += 900;
                i--;
            }
        }
        if(i == 0) {
            if(s[0] == 'I') {
                result++;
            } else if(s[0] == 'V') {
                result += 5;
            } else if(s[0] == 'X') {
                result += 10;
            } else if(s[0] == 'L') {
                result += 50;
            } else if(s[0] == 'C') {
                result += 100;
            } else if(s[0] == 'D') {
                result += 500;
            } else {
                result += 1000;
            }
        }
        return result;
    }
};

int main() {
	string str("III");
	Solution s;
	cout << s.romanToInt(str) << endl;
	return 0;
}