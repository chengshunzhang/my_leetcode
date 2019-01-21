#include <vector>
#include <iostream>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(!matrix.empty() && !matrix[0].empty()) {
            int m = matrix.size(), n = matrix[0].size();
            sums.resize(m + 1);
            for(int i = 0; i <= m; i++) {
                sums[i].resize(n + 1, 0);
            }
            sums[1][1] = matrix[0][0];
            for(int j = 2; j <= n; j++) {
                sums[1][j] = sums[1][j - 1] + matrix[0][j - 1];
            }
            for(int i = 2; i <= m; i++) {
                sums[i][1] = sums[i - 1][1] + matrix[i - 1][0];
            }
            for(int i = 2; i <= m; i++) {
                for(int j = 2; j <= n; j++) {
                    sums[i][j] = sums[i - 1][j] + sums[i][j - 1] + matrix[i - 1][j - 1] - sums[i - 1][j - 1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1] -
            sums[row1][col2 + 1] + sums[row1][col1];
    }
};

int main() {
	vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
									{5, 6, 3, 2, 1},
									{1, 2, 0, 1, 5},
									{4, 1, 0, 1, 7},
									{1, 0, 3, 0, 5}};
	NumMatrix numMatrix(matrix);
	cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
	cout << numMatrix.sumRegion(1, 1, 2, 2) << endl;
	cout << numMatrix.sumRegion(1, 2, 2, 4) << endl;
	return 0;
}