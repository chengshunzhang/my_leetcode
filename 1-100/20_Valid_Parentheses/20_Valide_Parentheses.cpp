#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char c;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if(st.empty())
            	return false;
            else {
                c = st.top();
                if((c == '(' && s[i] != ')') || (c == '{' && s[i] != '}') || (c == '[' && s[i] != ']'))
                    return false;
                st.pop();
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};

int main() {
	string s("(]");
	Solution ss;
	cout << ss.isValid(s) << endl;
	return 0;
}