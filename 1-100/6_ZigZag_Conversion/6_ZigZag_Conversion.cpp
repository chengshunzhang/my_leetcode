#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1) {
            return s;
        }
        int T = 2 * numRows - 2, count = 0;
        string result(n, ' ');
        for(int i = 0; i < numRows; i++) {
            for(int j = i; j < s.size(); j += T) {
                result[count++] = s[j];
                if(i > 0 && i < numRows - 1) {
                    if(j + T - 2 * i < s.size()) {
                        result[count++] = s[j + T - 2 * i];
                    } 
                }
            }   
        }
        return result;
    }
};

int main() {
	string s1("PAYPALISHIRING");
	Solution s;
	cout << s.convert(s1, 10) << endl;
	return 0;
}