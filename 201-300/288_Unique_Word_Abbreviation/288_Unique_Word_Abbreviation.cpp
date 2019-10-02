#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class ValidWordAbbr {
private:
    unordered_map<string, string> abbrToWord;
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for(string word : dictionary) {
            int n = word.size();
            string abbr = word[0] + to_string(n - 2) + word[n - 1];
            if(abbrToWord.find(abbr) == abbrToWord.end()) {
                abbrToWord[abbr] = word;
            } else if(abbrToWord[abbr] != word) {
                abbrToWord[abbr] = "";
            }
        }
    }
    
    bool isUnique(string word) {
        int n = word.size();
        string abbr = word[0] + to_string(n - 2) + word[n - 1];
        return abbrToWord.find(abbr) == abbrToWord.end() || abbrToWord[abbr] == word;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */

int main() {
    vector<string> dictionary = {"deer", "door", "cake", "card"};
    ValidWordAbbr validWordAbbr(dictionary);
    cout << validWordAbbr.isUnique("dear") << endl;
    return 0;
}