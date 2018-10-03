#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> m;
        for(int i = 0; i < wordList.size(); i++) {
            m[wordList[i]] = i;
        }
        if(!m.count(endWord)) {
            return 0;
        }
        int n = beginWord.size(), result = 1;
        queue<string> q;
        q.push(beginWord);
        q.push("");
        while(!q.empty()) {
            string str = q.front();
            q.pop();
            if(str != "") {
                for(int i = 0; i < n; i++) {
                    for(char c = 'a'; c <= 'z'; c++) {
                        if(c == str[i]) {
                            continue;
                        } else {
                            char tmp = str[i];
                            str[i] = c;
                            if(m.count(str)) {
                                if(str == endWord) {
                                    return result + 1;
                                }
                                q.push(str);
                                m.erase(str);
                            }
                            str[i] = tmp;
                        }
                    }
                }
            } else if(!q.empty()) {
                q.push("");
                result++;
            }
        }
        return 0;
    }
};

int main() {
	Solution s;
	string beginWord("hit"), endWord("cog");
	vector<string> wordList;
	wordList.push_back("hot");wordList.push_back("dot");wordList.push_back("dog");wordList.push_back("lot");wordList.push_back("log");wordList.push_back("cog");
	cout << s.ladderLength(beginWord, endWord, wordList) << endl;
	return 0;
}