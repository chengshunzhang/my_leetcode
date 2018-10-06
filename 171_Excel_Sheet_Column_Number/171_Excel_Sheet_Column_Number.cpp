#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size() - 1, result = 0;
        for(int i = n, j = 0; i >= 0; i--, j++) {
            result = result + pow(26, j) * (s[i] - 'A' + 1);
        }
        return result;
    }
};

int main() {
	Solution so;
	string s("AA");
	cout << so.titleToNumber(s) << endl;
	return 0;
}