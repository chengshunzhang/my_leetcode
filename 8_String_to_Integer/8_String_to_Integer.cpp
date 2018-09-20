#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0, result;
        while(i < str.size()) {
            if(str[i] == ' ')
                i++;
            else if(str[i] == '0' && i < str.size() - 1 && str[i + 1] - '0' >= '0' && str[i + 1] - '0' <= '9')
            	i++;
            else if(str[i] == '+' || str[i] == '-' || (str[i] - '0' > 0 && str[i] - '0' <= 9)){
                int start, end;
                if(str[i] == '+' || str[i] == '-') {
                    start = i + 1;
                    while(str[start] == '0')
                    	start++;
                }
                else
                    start = i;
                end = start;
                while(str[end] - '0' >= 0 && str[end] - '0' <= 9)
                    end++;
                string s(str, start, end - start);
                uint max_n = (uint)1 << 31;
                int max_p = max_n - 1;
                string sn = to_string(max_n), sp = to_string(max_p);
                if(s.size() > sn.size())
                    return str[i] == '-' ? -max_n : max_p;
                if(s.size() == sn.size()) {
                    if(s > sp && str[i] != '-')
                        return max_p;
                    if(s > sn && str[i] == '-')
                    	return -max_n;
                }
                return str[i] == '-' ? -atoi(s.c_str()) : atoi(s.c_str());
            }
            else
                return 0;
        }
        return 0;
    }
};

int main() {
	string s("0-1");
	Solution ss;
	cout << ss.myAtoi(s) << endl;
	return 0;
}