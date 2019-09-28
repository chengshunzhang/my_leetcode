#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        if(strings.empty()) {
            return result;
        }
        unordered_map<string, vector<string>> groups;
        for(string word : strings) {
            string temp = word;
            int diff = word[0] - 'a';
            for(int i = 0; i < word.size(); i++) {
                word[i] = (word[i] - diff + 26) % 26;
            }
            groups[word].push_back(temp);
        }
        for(auto it = groups.begin(); it != groups.end(); it++) {
            result.push_back(it -> second);
        }
        return result;
    }
};

int main() {
    vector<string> strings = {"h", "k", "r", "r", "t"};
    Solution sol;
    vector<vector<string>> result = sol.groupStrings(strings);
    for(vector<string> group : result) {
        for(string str : group) {
            cout << str << "  ";
        }
        cout << endl;
    }
    return 0;
}