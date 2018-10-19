#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        for(int i = 0; i <= n / 2; i++) {
            int j = n - 1 - i;
            if(num[i] == '0' && num[j] == '0') {
                continue;
            }
            if(num[i] == '1' && num[j] == '1') {
                continue;
            }
            if(num[i] == '6' && num[j] == '9') {
                continue;
            }
            if(num[i] == '8' && num[j] == '8') {
                continue;
            }
            if(num[i] == '9' && num[j] == '6') {
                continue;
            }
            return false;
        }
        return true;
    }
};

int main() {
	Solution s;
	cout << s.isStrobogrammatic("101") << endl;
	return 0;
}