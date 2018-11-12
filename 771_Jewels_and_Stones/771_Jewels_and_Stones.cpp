#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, bool> hash;
        for(int i = 0; i < J.size(); i++) {
            hash[J[i]] = true;
        }
        int count = 0;
        for(int i = 0; i < S.size(); i++) {
            if(hash.count(S[i])) {
                count++;
            }
        }
        return count;
    }
};

int main() {
	Solution s;
	string J("aA"), S("aAAbbbb");
	cout << s.numJewelsInStones(J, S) << endl;
	return 0;
}