#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                continue;
            } else if(s[i] == '+') {
                st.push(-1);
            } else if(s[i] == '-') {
            	st.push(-2);
            } else if(s[i] == '(') {
            	st.push(-3);
            } else if(s[i] == ')') {
                int operand1 = st.top();
                st.pop();
                st.pop();
                while(!st.empty() && st.top() != -3) {
                    int temp = st.top();
                    st.pop();
                    int operand2 = st.top();
                    st.pop();
                    if(temp == -1) {
                        operand1 = operand2 + operand1;
                    } else {
                        operand1 = operand2 - operand1;
                    }
                }
                st.push(operand1);
            } else {
                int num;
                int pos = i + 1;
                while(pos < s.size() && s[pos] != '+' && s[pos] != '-' && s[pos] != ' ' && s[pos] != ')') {
                    pos++;
                }
                num = atoi(s.substr(i, pos - i).c_str());
                i = pos - 1;
                if(st.empty() || st.top() == -3) {
                    st.push(num);
                } else {
                    int temp = st.top();
                    st.pop();
                    int operand2 = st.top();
                    st.pop();
                    if(temp == -1) {
                        num = operand2 + num;
                    } else {
                        num = operand2 - num;
                    }
                    st.push(num);
                }
            }
        }
        return st.top();
    }
};

int main() {
	string str("(1+(4+5+2)-3)+(6+8)");
	Solution s;
	cout << s.calculate(str) << endl;
	return 0;
}