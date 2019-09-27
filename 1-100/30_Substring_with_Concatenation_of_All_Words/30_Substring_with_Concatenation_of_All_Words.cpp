#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s.empty() || words.empty()) {
            return result;
        }
        int len = words[0].size(), n = words.size();
        unordered_map<string, int> wordSet;
        for(string word : words) {
            wordSet[word]++;
        }
        for(int st = 0; st < len; st++) {
            int start = st, count = 0;
            unordered_map<string, int> temp;
            for(int i = start; i < s.size(); i += len) {
                string currWord = s.substr(i, len);
                if(wordSet.find(currWord) == wordSet.end()) {
                    temp.clear();
                    count = 0;
                    start = i + len;
                } else if(temp[currWord] == wordSet[currWord]) {
                    while(s.substr(start, len) != currWord) {
                        temp[s.substr(start, len)]--;
                        count--;
                        start += len;
                    }
                    start += len;
                } else {
                    temp[currWord]++;
                    count++;
                }
                if(count == n) {
                    result.push_back(start);
                    temp[s.substr(start, len)]--;
                    count--;
                    start += len;
                }
                if(start + n * len > s.size()) {
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
	string s = "barfoothefoobarman";
	vector<string> words = {"foo", "bar"};
	Solution sol;
	vector<int> result = sol.findSubstring(s, words);
	cout << '[';
	for(int index : result) {
		cout << index << ',';
	}
	cout << "\b]" << endl;
	return 0;
}