#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++) {
            string temp = tokens[i];
            if(temp == "+" || temp == "-" || temp == "*" || temp == "/") {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                if(temp == "+") {
                    st.push(operand1 + operand2);
                } else if(temp == "-") {
                    st.push(operand1 - operand2);
                } else if(temp == "*") {
                    st.push(operand1 * operand2);
                } else {
                    st.push(operand1 / operand2);
                }
            } else {
                st.push(stoi(temp));
            }
        }
        return st.top();
    }
};

int main() {
	string t[] = {"2", "1", "+", "3", "*"};
	vector<string> tokens(t,t+5);
	Solution s;
	cout << s.evalRPN(tokens) << endl;
	return 0;
}