#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if(numRows == 0) {
            return result;
        }
        vector<int> temp;
        result.push_back(vector<int> (1, 1));
        for(int i = 1; i < numRows; i++) {
            temp.push_back(1);
            for(int j = 1; j < i; j++) {
                temp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            temp.push_back(1);
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
};

int main() {
	int numRows = 5;
	Solution s;
	vector<vector<int> > res = s.generate(numRows);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}