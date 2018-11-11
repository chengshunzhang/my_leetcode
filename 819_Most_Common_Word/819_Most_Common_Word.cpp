#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    bool isCharacter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, bool> bannedHash;
        unordered_map<string, int> wordCount;
        int maxi = -1;
        string result = "";
        for(int i = 0; i < banned.size(); i++) {
            bannedHash[banned[i]] = true;
        }
        int pos = 0;
        while(!isCharacter(paragraph[pos])) {
            pos++;
        }
        while(pos < paragraph.size()) {
            int end = pos + 1;
            while(end < paragraph.size() && isCharacter(paragraph[end])) {
                end++;
            }
            string word = paragraph.substr(pos, end - pos);
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if(!bannedHash.count(word)) {
                wordCount[word]++;
                if(wordCount[word] > maxi) {
                    maxi = wordCount[word];
                    result = word;
                }
            }
            while(end < paragraph.size() && !isCharacter(paragraph[end])) {
                end++;
            }
            pos = end;
        }
        return result;
    }
};

int main() {
	string paragraph("Bob hit a ball, the hit BALL flew far after it was hit.");
	vector<string> banned;
	banned.push_back("hit");
	Solution s;
	cout << s.mostCommonWord(paragraph, banned) << endl;
	return 0;
}