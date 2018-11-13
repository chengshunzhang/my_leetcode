#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    pair<int, int> nextPos(vector<string>& source, int row, int col) {
        for(int j = col; j < source[row].size() - 1; j++) {
            if(source[row][j] == '*' && source[row][j + 1] == '/') {
                return pair<int, int> (row, j + 2);
            }
        }
        for(int i = row + 1; i < source.size(); i++) {
            for(int j = 0; j + 1 < source[i].size(); j++) {
                if(source[i][j] == '*' && source[i][j + 1] == '/') {
                    return pair<int, int> (i, j + 2);
                }
            }
        }
        return pair<int, int> (-1, -1);
    }
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        string temp = "";
        int start;
        for(int i = 0; i < source.size(); i++) {
            start = 0;
            for(int j = 0; j + 1 < source[i].size(); j++) {
                if(source[i][j] == '/' && source[i][j + 1] == '/') {
                    temp += source[i].substr(start, j - start);
                    start = source[i].size();
                    break;
                }
                if(source[i][j] == '/' && source[i][j + 1] == '*') {
                    temp += source[i].substr(start, j - start);
                    pair<int, int> pos = nextPos(source, i, j + 2);
                    i = pos.first;
                    j = pos.second - 1;
                    start = j + 1;
                }
            }
            if(start != source[i].size()) {
                temp += source[i].substr(start);
            }
            if(temp != "") {
                result.push_back(temp);
                temp = "";
            }
        }
        return result;
    }
};

int main() {
	Solution s;
	vector<string> source;
	source.push_back("main() { ");
	source.push_back("  int a = 1; /* Its comments here ");
	source.push_back("");
	source.push_back("   ");
	source.push_back("  */ return 0;");
	source.push_back("} ");
	vector<string> res = s.removeComments(source);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}