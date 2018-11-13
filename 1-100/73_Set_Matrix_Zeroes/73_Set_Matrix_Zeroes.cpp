#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        if(matrix.empty()) {
            return;
        }
        bool row1 = false, col1 = false;
        int m = matrix.size(), n = matrix[0].size();
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) {
                row1 = true;
            }
        }
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                col1 = true;
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for(int j = 1; j < n; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(row1) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if(col1) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
	vector<vector<int> > matrix(3, vector<int> (3, 1));
	matrix[1][1] = 0;
	Solution s;
	s.setZeroes(matrix);
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}