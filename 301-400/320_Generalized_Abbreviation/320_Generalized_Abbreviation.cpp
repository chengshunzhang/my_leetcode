#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    void helper(vector<string>& result, string word, int start) {
        int n = word.size();
        result.push_back(word);
        if(start >= n) {
            return;
        }
        for(int i = start; i < n; i++) {
            for(int len = 1; len + i <= n; len++) {
                string lenS = to_string(len);
                helper(result, word.substr(0, i) + lenS + word.substr(i + len), i + lenS.size() + 1);
            }
        }
    }
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        helper(result, word, 0);
        return result;
    }
};

int main() {
	string word = "word";
	Solution sol;
	vector<string> result = sol.generateAbbreviations(word);
	for(string str : result) {
		cout << str << "  ";
	}
	cout << endl;
	return 0;
}