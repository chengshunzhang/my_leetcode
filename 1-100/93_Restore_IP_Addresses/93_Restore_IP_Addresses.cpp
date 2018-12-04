#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    void helper(string& s, vector<string>& result, string& temp, int start, int segment) {
        if(start >= s.size()) {
            return;
        }
        int curLen = temp.size();
        if(segment == 4) {
            int len = s.size() - start;
            if(len > 3 || stoi(s.substr(start)) > 255 || (len > 1 && s[start] == '0')) {
                return;
            }
            temp += s.substr(start, s.size() - start);
            result.push_back(temp);
            temp = temp.substr(0, curLen);
            return;
        }
        for(int len = 3; len > 0; len--) {
            if(stoi(s.substr(start, len)) > 255 || (len > 1 && s[start] == '0')) {
                continue;
            }
            temp += s.substr(start, len) + ".";
            helper(s, result, temp, start + len, segment + 1);
            temp = temp.substr(0, curLen);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string temp = "";
        helper(s, result, temp, 0, 1);
        return result;
    }
};

int main() {
	string str = "25525511135";
	Solution s;
	vector<string> res = s.restoreIpAddresses(str);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}