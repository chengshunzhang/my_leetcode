#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        string str = to_string(x), strNoSign;
        if(str[0] == '-') {
            strNoSign.assign(str, 1, str.size() - 1);
        } else {
            strNoSign.assign(str);
        }
        for(int i = 0, j = strNoSign.size() - 1; i < j; i++, j--) {
            char temp = strNoSign[i];
            strNoSign[i] = strNoSign[j];
            strNoSign[j] = temp;
        }
        int max_p = ((uint) 1 << 31) - 1;
        uint max_n = (uint) 1 << 31;
        string str_p = to_string(max_p), str_n = to_string(max_n);
        if(str[0] == '-') {
            return strNoSign.size() == str_n.size() && strNoSign > str_n ? 0 : - atoi(strNoSign.c_str());
        } else {
            return strNoSign.size() == str_p.size() && strNoSign > str_p ? 0 : atoi(strNoSign.c_str());
        }
    }
};

int main() {
	Solution s;
	int x = -2147483648;
	cout << s.reverse(x) << endl;
	return 0;
}