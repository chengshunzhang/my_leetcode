#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
public:
    int myAtoi(string str) {
        bool negative = false;
        int start = 0, n = str.size();
        while(start < n && str[start] == ' ') {
            start++;
        }
        if(start < n && (str[start] == '-' || str[start] == '+')) {
            if(str[start] == '-') {
                negative = true;
            }
            start++;
        }
        if(start == n || !isDigit(str[start])) {
            return 0;
        }
        int sum = 0;
        while(start < n && isDigit(str[start])) {
            if(sum > 0 && INT_MAX / sum < 10) {
                return negative ? INT_MIN : INT_MAX;
            }
            if(sum > 0 && INT_MAX / sum == 10 &&
               INT_MAX - sum * 10 < str[start] - '0') {
                return negative ? INT_MIN : INT_MAX;
            }
            int temp = str[start] - '0';
            sum = sum * 10 + temp;
            start++;
        }
        return negative ? -sum : sum;
    }
};

int main() {
	string s("0-1");
	Solution ss;
	cout << ss.myAtoi(s) << endl;
	return 0;
}