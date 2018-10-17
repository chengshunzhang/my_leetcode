#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size(), row = m - 1, col = 0;
        while(row > -1 && col < n) {
            if(matrix[row][col] == target) {
                return true;
            } else if(matrix[row][col] > target) {
                row--;
            } else {
                col++;
            }
        }
        return false;
    }
};

int main() {
	vector<vector<int> > matrix;
	Solution s;
	cout << s.searchMatrix(matrix, 1) << endl;
	return 0;
}