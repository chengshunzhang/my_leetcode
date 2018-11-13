#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n = max(num1.size(), num2.size()) + 1;
        string result(n, '0');
        num1 += string(n - num1.size(), '0');
        num2 += string(n - num2.size(), '0');
        int carry = 0;
        for(int i = 0; i < n; i++) {
            int temp = num1[i] - '0' + num2[i] - '0' + carry;
            int sum = temp % 10;
            carry = temp / 10;
            result[i] = sum + '0';
        }
        if(carry) {
            result[n - 1] = '1';
        }
        reverse(result.begin(), result.end());
        if(n != 1 && result[0] == '0') {
            return result.substr(1);
        }
        return result;
    }
};

int main() {
	Solution s;
	cout << s.addStrings("123", "4") << endl;
	return 0;
}