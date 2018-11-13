#include <vector>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> result(n, 0);
        int preTime = 0;
        bool type = 0;
        for(int i = 0; i < logs.size(); i++) {
            int start = 0, end;
            while(logs[i][start] != 's' && logs[i][start] != 'e') {
                start++;
            }
            if(logs[i][start] == 's') {
                end = start + 4;
            } else {
                end = start + 2;
            }
            int id = atoi(logs[i].substr(0, start - 1).c_str()), curTime = atoi(logs[i].substr(end + 2).c_str());
            if(logs[i][start] == 's') {
                if(!st.empty()) {
                    if(type == 0) {
                        result[st.top()] += curTime - preTime;
                    } else {
                        result[st.top()] += curTime - preTime - 1;
                    }
                }
                st.push(id);
            } else {
                if(type == 0) {
                    result[st.top()] += curTime - preTime + 1;
                } else {
                    result[st.top()] += curTime - preTime;
                }
                st.pop();
            }
            type = logs[i][start] == 's' ? 0 : 1;
            preTime = curTime;
        }
        return result;
    }
};

int main() {
	Solution s;
	int n = 2;
	vector<string> logs;
	logs.push_back("0:start:0");
	logs.push_back("1:start:2");
	logs.push_back("1:end:5");
	logs.push_back("0:end:6");
	vector<int> res = s.exclusiveTime(n, logs);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}