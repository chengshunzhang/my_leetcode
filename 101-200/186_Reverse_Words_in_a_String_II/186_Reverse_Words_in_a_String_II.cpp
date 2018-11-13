#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWords(vector<char>& str) {
        for(int i = 0; i < str.size(); i++) {
            int j = i + 1;
            while(j < str.size() && str[j] != ' ') {
                j++;
            }
            reverse(str.begin() + i, str.begin() + j);
            i = j;
        }
        reverse(str.begin(), str.end());
    }
};

int main() {
	char c[] = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
	vector<char> str(c, c + 15);
	Solution s;
	s.reverseWords(str);
	for(int i = 0; i < str.size(); i++) {
		cout << str[i];
	}
	cout << endl;
	return 0;
}