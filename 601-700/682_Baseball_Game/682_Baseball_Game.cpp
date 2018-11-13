#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int sum = 0;
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i] == "+") {
                int lastOne = st.top();
                st.pop();
                int scoreThisRound = lastOne + st.top();
                sum += scoreThisRound;
                st.push(lastOne);
                st.push(scoreThisRound);
            } else if(ops[i] == "D") {
                int scoreThisRound = 2 * st.top();
                sum += scoreThisRound;
                st.push(scoreThisRound);
            } else if(ops[i] == "C") {
                sum -= st.top();
                st.pop();
            } else {
                int scoreThisRound = stoi(ops[i]);
                st.push(scoreThisRound);
                sum += scoreThisRound;
            }
        }
        return sum;
    }
};

int main() {
	string n[] = {"5","2","C","D","+"};
	vector<string> ops(n,n+5);
	Solution s;
	cout << s.calPoints(ops) << endl;
	return 0;
}