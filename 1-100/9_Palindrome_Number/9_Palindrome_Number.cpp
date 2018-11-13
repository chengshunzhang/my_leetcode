#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        string strR(str);
        int n = str.size();
        for(int i = 0, j = n - 1; i < j; i++, j--) {
            int temp = strR[i];
            strR[i] = strR[j];
            strR[j] = temp;
        }
        return str == strR;
    }
};

int main() {
	Solution s;
	cout << s.isPalindrome(121) << endl;
	return 0;
}