#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        int n = s.size();
        unordered_map<string, int> m;
        for(int i = 0; i + 9 < n; i++) {
            string temp = s.substr(i, 10);
            if(m.count(temp) && m[temp] != -1) {
                result.push_back(temp);
                m[temp] = -1;
            } else if(!m.count(temp)) {
                m[temp] = 1;
            }
        }
        return result;
    }
};

int main() {
	string s("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	Solution sol;
	vector<string> res = sol.findRepeatedDnaSequences(s);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}