#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.empty()) {
            return 0;
        }
        vector<int> represents(words.size());
        for(int i = 0; i < words.size(); i++) {
            int repre = 0;
            for(int j = 0; j < words[i].size(); j++) {
                int pos = words[i][j] - 'a';
                repre |= (1 << pos);
            }
            represents[i] = repre;
        }
        int result = 0;
        for(int i = 0; i + 1 < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                if((represents[i] & represents[j]) == 0) {
                    int cur = words[i].size() * words[j].size();
                    if(cur > result) {
                        result = cur;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
	Solution s;
	vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
	cout << s.maxProduct(words) << endl;
	return 0;
}