#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int result = ((uint)1 << 31) - 1, word1P = -1, word2P = -1;
        for(int i = 0; i < words.size(); i++) {
            if(words[i] == word1) {
                word1P = i;
                if(word2P != -1) {
                    int temp = word1P - word2P;
                    if(temp < result) {
                        result = temp;
                    }
                }
            }
            if(words[i] == word2) {
                word2P = i;
                if(word1P != -1) {
                    int temp = word2P - word1P;
                    if(temp < result) {
                        result = temp;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
	vector<string> words;
	words.push_back("practice");words.push_back("makes");words.push_back("perfect");words.push_back("coding");
	words.push_back("makes");
	string word1("coding");
	string word2("practice");
	Solution s;
	cout << s.shortestDistance(words, word1, word2) << endl;
	return 0;
}