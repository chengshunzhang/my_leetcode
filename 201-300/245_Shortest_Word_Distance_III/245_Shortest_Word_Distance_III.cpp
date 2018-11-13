#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int result = ((uint)1 << 31) - 1, word1P = -1, word2P = -1;
        if(word1 == word2) {
            for(int i = 0; i < words.size(); i++) {
                if(words[i] == word1) {
                    if(word1P != -1) {
                        int distance = i - word1P;
                        if(distance < result) {
                            result = distance;
                        }
                    }
                    word1P = i;
                } 
            }
        } else {
            for(int i = 0; i < words.size(); i++) {
                if(words[i] == word1) {
                    word1P = i;
                    if(word2P != -1) {
                        int distance = word1P - word2P;
                        if(distance < result) {
                            result = distance;
                        }
                    }
                }
                if(words[i] == word2) {
                    word2P = i;
                    if(word1P != -1) {
                        int distance = word2P - word1P;
                        if(distance < result) {
                            result = distance;
                        }
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
	string word1("makes");
	string word2("makes");
	Solution s;
	cout << s.shortestWordDistance(words, word1, word2) << endl;
	return 0;
}