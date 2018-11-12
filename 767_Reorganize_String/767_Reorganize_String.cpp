#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        vector<int> words(26, 0);
        for(int i = 0; i < n; i++) {
            words[S[i] - 'a']++;
        }
        int maximum = words[0], cur = 0;
        char c = 'a';
        for(int i = 1; i < 26; i++) {
            if(words[i] > maximum) {
                maximum = words[i];
                cur = i;
                c = i + 'a';
            }
        }
        if(n - maximum < maximum - 1) {
            return "";
        }
        int interval = (n + 1) / maximum;
        for(int start = 0; start < interval; start++) {
            for(int i = start; i < n; i += interval) {
                if(words[cur] == 0) {
                    do {
                       cur = (cur + 1) % 26; 
                    } while(words[cur] == 0);
                    c = cur + 'a';
                }
                S[i] = c;
                words[cur]--;
            }
        }
        return S;
    }
};

int main() {
	Solution s;
	string str("aab");
	cout << s.reorganizeString(str) << endl;
	return 0;
}