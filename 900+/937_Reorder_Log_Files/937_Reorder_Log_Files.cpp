#include <vector>
#include <iostream>
using namespace std;

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool myComp(string s1, string s2) {
    int pos1 = s1.find(' '), pos2 = s2.find(' ');
    string identifier1 = s1.substr(0, pos1), identifier2 = s2.substr(0, pos2);
    string content1 = s1.substr(pos1 + 1), content2 = s2.substr(pos2 + 1);
    if(content1 == content2) {
        return identifier1 < identifier2;
    }
    return content1 < content2;
}
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs, stringLogs;
        for(string log : logs) {
            if(isDigit(log[log.find(' ') + 1])) {
                digitLogs.push_back(log);
            } else {
                stringLogs.push_back(log);
            }
        }
        sort(stringLogs.begin(), stringLogs.end(), myComp);
        vector<string> result;
        result.insert(result.end(), stringLogs.begin(), stringLogs.end());
        result.insert(result.end(), digitLogs.begin(), digitLogs.end());
        return result;
    }
};

int main() {
	Solution s;
	vector<string> logs = {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
	vector<string> res = s.reorderLogFiles(logs);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}