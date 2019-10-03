#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        int first = 0, second = 1, n = s.size();
        while(second < n) {
            if(s[first] == '+' && s[second] == '+') {
                s[first] = s[second] = '-';
                result.push_back(s);
                s[first] = s[second] = '+';
            }
            first++;
            second++;
        }
        return result;
    }
};

int main() {
	string s = "++++";
	Solution sol;
	vector<string> result = sol.generatePossibleNextMoves(s);
	for(string str : result) {
		cout << str << endl;
	}
	return 0;
}