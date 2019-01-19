#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    bool helper(string num, long first, long second) {
        long sum = first + second;
        if(num[0] == '0' && sum != 0) {
            return false;
        }
        for(int len = 1; len <= num.size(); len++) {
            long cur = stol(num.substr(0, len));
            if(cur > sum) {
                return false;
            }
            if(cur == sum) {
                if(len == num.size()) {
                    return true;
                } else {
                    return helper(num.substr(len), second, cur);
                }
            }
        }
        return false;
    }
public:
    bool isAdditiveNumber(string num) {
        if(num.size() < 3) {
            return false;
        }
        if(num[0] == '0') {
            long first = 0;
            if(num[1] == '0') {
                long second = 0;
                return helper(num.substr(2), first, second);
            }
            for(int len = 1; len < num.size() / 2 + 1; len++) {
                int second = stol(num.substr(1, len));
                if(helper(num.substr(len + 1), first, second)) {
                    return true;
                }
            }
            return false;
        } else {
            for(int len1 = 1; len1 < num.size() / 2 + 1; len1++) {
                long first = stol(num.substr(0, len1));
                if(num[len1] == '0') {
                    long second = 0;
                    if(helper(num.substr(len1 + 1), first, second)) {
                        return true;
                    }
                } else {
                    for(int len2 = 1; len2 < num.size() / 2 + 1 &&
                        len1 + len2 < num.size(); len2++) {
                        long second = stol(num.substr(len1, len2));
                        if(helper(num.substr(len1 + len2), first, second)) {
                            return true;
                        }
                    }
                }     
            }
            return false;
        }
    }
};

int main() {
	Solution s;
	cout << s.isAdditiveNumber("121474836472147483648") << endl;
	return 0;
}