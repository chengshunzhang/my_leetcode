#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        }
        string s1 = "11";
        for(int i = 2; i < n; i++) {
            int len = s1.size();
            string s2;
            for(int j = 0; j < len - 1; j++) {
                int count = 1;
                while(j < len - 1 && s1[j] == s1[j + 1]) {
                    count++;
                    j++;
                }
                s2.append(to_string(count) + s1[j]);
            }
            if(s1[len - 1] != s1[len - 2]) {
                s2.append(to_string(1) + s1[len - 1]);
            }
            s1.assign(s2);
        }
        return s1;
    }
};

int main() {
	int n = 5;
	Solution s;
	cout << s.countAndSay(n) << endl;
	return 0;
}