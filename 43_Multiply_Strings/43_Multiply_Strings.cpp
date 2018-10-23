#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string result(num1.size() + num2.size(), '0');
        for(int i = 0; i < num2.size(); i++) {
            int carry = 0, digit = num2[i] - '0';
            for(int j = 0; j < num1.size(); j++) {
                int temp = (num1[j] - '0') * digit + carry + result[i + j] - '0';
                int product = temp % 10;
                carry = temp / 10;
                result[i + j] = product + '0';
            }
            if(carry) {
                result[i + num1.size()] = carry + '0';
            }
        }
        reverse(result.begin(), result.end());
        int i = 0;
        while(result[i] == '0') {
            i++;
        }
        return result.substr(i);
    }
};

int main() {
	Solution s;
	cout << s.multiply("2", "3") << endl;
	return 0;
}