#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > result;
        unordered_map<string, int> hash;
        int pos = 0;
        for(int i = 0; i < strs.size(); i++) {
            string temp(strs[i]);
            sort(temp.begin(), temp.end());
            if(!hash.count(temp)) {
                result.push_back(vector<string> (1, strs[i]));
                hash[temp] = pos++;
            } else {
                result[hash[temp]].push_back(strs[i]);
            }
        }
        return result;
    }
};

int main() {
	Solution s;
	vector<string> strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");
	vector<vector<string> > res = s.groupAnagrams(strs);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}