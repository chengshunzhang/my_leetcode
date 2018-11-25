#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> hash;
        unordered_map<int, bool> bulls;
        string result;
        int A = 0, B = 0;
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[i]) {
                A++;
                bulls[i] = true;
            } else {
                hash[secret[i]]++;
            }
        }
        for(int i = 0; i < guess.size(); i++) {
            if(!bulls.count(i) && hash.count(guess[i])) {
                B++;
                if(--hash[guess[i]] == 0) {
                    hash.erase(hash.find(guess[i]));
                }
            }
        }
        return to_string(A) + 'A' + to_string(B) + 'B';
    }
};

int main() {
	string secret("1807"), guess("7810");
	Solution s;
	cout << s.getHint(secret, guess) << endl;
	return 0;
}