#include <vector>
#include <string>
#include <iostream>
using namespace std;
struct position {
    int row;
    int col;
    position(int r, int c): row(r), col(c) {}
};
class Solution {
private:
    void solveHelper(vector<vector<string> >& result, vector<string>& temp, vector<vector<bool> >& isValid, int row, int n) {
        for(int i = 0; i < n; i++) {
            if(isValid[row][i]) {
                temp[row][i] = 'Q';
                if(row == n - 1) {
                    result.push_back(temp);
                    temp[row][i] = '.';
                    break;
                }
                vector<position> pos;
                for(int j = row + 1, k = i + 1; j < n && k < n; j++, k++) {
                    if(isValid[j][k]) {
                        isValid[j][k] = false;
                        pos.push_back(position (j, k));
                    }  
                }
                for(int j = row + 1, k = i - 1; j < n && k >= 0; j++, k--) {
                    if(isValid[j][k]) {
                        isValid[j][k] = false;
                        pos.push_back(position (j, k));
                    }  
                }
                for(int j = row + 1; j < n; j++) {
                    if(isValid[j][i]) {
                        isValid[j][i] = false;
                        pos.push_back(position (j, i));
                    }  
                }
                solveHelper(result, temp, isValid, row + 1, n);
                temp[row][i] = '.';
                for(int ix = 0; ix < pos.size(); ix++) {
                    isValid[pos[ix].row][pos[ix].col] = true;
                }
            }

        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        string str;
        for(int i = 0; i < n; i++) {
            str.append(".");
        }
        vector<string> temp(n, str);
        vector<vector<bool> > isValid(n, vector<bool> (n, true));
        solveHelper(result, temp, isValid, 0, n);
        return result;
    }
};
int main() {
	Solution s;
	vector<vector<string> > res = s.solveNQueens(5);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << endl;
		}
		cout << endl << endl;
	}
	return 0;
}