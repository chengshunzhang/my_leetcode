#include <deque>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        deque<int> dq;
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                continue;
            } else if(s[i] == '+') {
                dq.push_back(-1);
            } else if(s[i] == '-') {
                dq.push_back(-2);
            } else if(s[i] == '*') {
                dq.push_back(-3);
            } else if(s[i] == '/') {
                dq.push_back(-4);
            } else {
                int pos = i + 1;
                while(pos < n && s[pos] != '+' && s[pos] != '-' && s[pos] != '*' && s[pos] != '/' && s[pos] != ' ') {
                    pos++;
                }
                int operand1 = atoi(s.substr(i, pos - i).c_str());
                i = pos - 1;
                if(!dq.empty() && (dq.back() == -3 || dq.back() == -4)) {
                    int op = dq.back();
                    dq.pop_back();
                    int operand2 = dq.back();
                    dq.pop_back();
                    operand1 = (op == -3 ? operand2 * operand1 : operand2 / operand1);
                }
                dq.push_back(operand1);
            }
        }
        int operand1 = dq.front();
        dq.pop_front();
        while(!dq.empty()) {
            int op = dq.front();
            dq.pop_front();
            int operand2 = dq.front();
            dq.pop_front();
            operand1 = (op == -1 ? operand1 + operand2 : operand1 - operand2);
        }
        return operand1;
    }
};

int main() {
	Solution s;
	string str("2+3*3");
	cout << s.calculate(str) << endl;
	return 0;
}