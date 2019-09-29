#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void helper(vector<string>& result, string& str, vector<int>& chars, int pos) {
        int n = str.size();
        if(pos == n / 2) {
            if(n % 2 == 1) {
                for(int i = 0; i < 256; i++) {
                    if(chars[i] == 1) {
                        str[pos] = i;
                        break;
                    }
                }
            }
            result.push_back(str);
            return;
        }
        int sym = str.size() - pos - 1;
        for(int i = 0; i < 256; i++) {
            if(chars[i] > 1) {
                str[pos] = str[sym] = i;
                chars[i] -= 2;
                helper(result, str, chars, pos + 1);
                chars[i] += 2;
            }
        }
    }
public:
    vector<string> generatePalindromes(string s) {
        vector<string> result;
        int n = s.size();
        vector<int> chars(256, 0);
        for(int i = 0; i < n; i++) {
            chars[s[i]]++;
        }
        int odd = 0;
        for(int i = 0; i < 256; i++) {
            if(chars[i] % 2 == 1) {
                odd++;
            }
            if(odd > 1) {
                return result;
            }
        }
        string str = s;
        helper(result, str, chars, 0);
        return result;
    }
};

int main() {
    string s = "aab";
    Solution sol;
    vector<string> result = sol.generatePalindromes(s);
    for(string s : result) {
        cout << s << endl;
    }
    return 0;
}