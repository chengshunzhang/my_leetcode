#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int, int> > chars(26, make_pair(0, 0));
        for(int i = 0; i < s.size(); i++) {
            chars[s[i] - 'a'].first++;
            chars[s[i] - 'a'].second = i;
        }
        int result = -1;
        for(int i = 0; i < 26; i++) {
            if(chars[i].first == 1 && (result == -1 || chars[i].second < result)) {
                result = chars[i].second;
            }
        }
        return result;
    }
};

int main() {
	string str("leetcode");
	Solution s;
	cout << s.firstUniqChar(str) << endl;
	return 0;
}