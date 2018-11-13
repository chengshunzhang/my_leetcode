#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.empty()) {
            return 0;
        }
        int pos = 0, times = 1;
        char cur = chars[0];
        for(int i = 1; i < chars.size(); i++) {
            if(chars[i] == cur) {
                times++;
            } else {
                chars[pos++] = cur;
                if(times > 1) {
                    string num = to_string(times);
                    for(int j = 0; j < num.size(); j++) {
                        chars[pos++] = num[j];
                    }
                }
                cur = chars[i];
                times = 1;
            }
        }
        if(pos < chars.size()) {
            chars[pos++] = cur;
            if(times > 1) {
                string num = to_string(times);
                for(int j = 0; j < num.size(); j++) {
                    chars[pos++] = num[j];
                }
            }
            if(pos < chars.size()) {
                chars.erase(chars.begin() + pos);
            }
        }
        return pos;
    }
};

int main() {
	char n[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
	vector<char> chars(n, n + 7);
	Solution s;
	cout << s.compress(chars) << endl;
	return 0;
}