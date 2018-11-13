#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size(), len = n - k;
        if(k == n) {
            return "0";
        }
        string result;
        result.push_back(num[0]);
        for(int i = 1; i < n; i++) {
            while(!result.empty() && num[i] < result.back() && k > 0) {
                result.pop_back();
                k--;
            }
            result.push_back(num[i]);
            if(k == 0) {
                result += num.substr(i + 1);
                break;
            }
        }
        result = result.substr(0, len);
        int pos = 0;
        while(pos < len && result[pos] == '0') {
            pos++;
        }
        if(pos == len) {
            return "0";
        }
        return result.substr(pos);
    }
};

int main() {
	string num("112");
	Solution s;
	cout << s.removeKdigits(num, 1) << endl;
	return 0;
}