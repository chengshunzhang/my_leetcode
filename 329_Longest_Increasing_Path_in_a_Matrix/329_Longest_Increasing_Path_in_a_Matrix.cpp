#include <vector>
#include <iostream>
using namespace std;

class Solution {
    private:
    int helper(vector<vector<int> >& matrix, vector<vector<int> >& sub, int row, int col) {
        int res = 1, temp = 1;
        int up = row - 1, down = row + 1, left = col - 1, right = col + 1;
        if(row > 0 && matrix[up][col] > matrix[row][col]) {
            if(sub[up][col] != -1) {
                temp += sub[up][col];
            } else {
                temp += helper(matrix, sub, up, col);
            }
            if(temp > res) {
                res = temp;
            }
            temp = 1;
        }
        if(down < matrix.size() && matrix[down][col] > matrix[row][col]) {
            if(sub[down][col] != -1) {
                temp += sub[down][col];
            } else {
                temp += helper(matrix, sub, down, col);
            }
            if(temp > res) {
                res = temp;
            }
            temp = 1;
        }
        if(col > 0 && matrix[row][left] > matrix[row][col]) {
            if(sub[row][left] != -1) {
                temp += sub[row][left];
            } else {
                temp += helper(matrix, sub, row, left);
            }
            if(temp > res) {
                res = temp;
            }
            temp = 1;
        }
        if(right < matrix[0].size() && matrix[row][right] > matrix[row][col]) {
            if(sub[row][right] != -1) {
                temp += sub[row][right];
            } else {
                temp += helper(matrix, sub, row, right);
            }
            if(temp > res) {
                res = temp;
            }
        }
        sub[row][col] = res;
        return res;
    }
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if(matrix.empty()) {
            return 0;
        }
        vector<vector<int> > sub(matrix.size(), vector<int> (matrix[0].size(), -1));
        int result = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(sub[i][j] == -1) {
                    int temp = helper(matrix, sub, i, j);
                    if(temp > result) {
                        result = temp;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
	vector<vector<int> > matrix;
	vector<int> temp;
	temp.push_back(9);temp.push_back(9);temp.push_back(4);
	matrix.push_back(temp);temp.clear();
	temp.push_back(6);temp.push_back(6);temp.push_back(8);
	matrix.push_back(temp);temp.clear();
	temp.push_back(2);temp.push_back(1);temp.push_back(1);
	matrix.push_back(temp);temp.clear();
	Solution s;
	cout << s.longestIncreasingPath(matrix) << endl;
	return 0;
}