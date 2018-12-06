#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string> > findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string> > hash;
        for(int i = 0; i < paths.size(); i++) {
            string directory;
            int pos = 0;
            while(pos < paths[i].size() && paths[i][pos] != ' ') {
                pos++;
            }
            directory = paths[i].substr(0, pos++) + "/";
            while(pos < paths[i].size()) {
                int j = pos + 1;
                while(j < paths[i].size() && paths[i][j] != '(') {
                    j++;
                }
                string file = paths[i].substr(pos, j - pos);
                pos = ++j;
                while(j < paths[i].size() && paths[i][j] != ')') {
                    j++;
                }
                hash[paths[i].substr(pos, j - pos)].push_back(directory + file);
                pos = j + 2;
            }
        }
        vector<vector<string> > result;
        for(unordered_map<string, vector<string> >::iterator it = hash.begin(); it != hash.end(); it++) {
            if(it -> second.size() > 1) {
                result.push_back(it -> second);
            }
        }
        return result;
    }
};

int main() {
	string p[] = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
	vector<string> paths(p, p + 4);
	Solution s;
	vector<vector<string> > res = s.findDuplicate(paths);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ',';
		}
		cout << "\b \b" << endl;
	}
	return 0;
}