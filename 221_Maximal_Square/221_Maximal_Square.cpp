#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if(matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > DP(m, vector<int> (n, 0));
        int result = 1 << 31;
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == '1') {
                DP[0][j] = 1;
                result = 1;
            }
        }
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == '1') {
                DP[i][0] = 1;
                result = 1;
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == '1') {
                    int temp = min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1]));
                    DP[i][j] = temp + 1;
                    if(DP[i][j] > result) {
                        result = DP[i][j];
                    }
                }
            }
        }
        return result * result;
    }
};

int main() {
	vector<vector<char> > matrix(4, vector<char> (5, '0'));
	matrix[0][0] = '1';matrix[0][2] = '1';matrix[1][0] = '1';matrix[1][2] = '1';matrix[1][3] = '1';
	matrix[1][4] = '1';matrix[2][0] = '1';matrix[2][1] = '1';matrix[2][2] = '1';matrix[2][3] = '1';
	matrix[2][4] = '1';matrix[3][0] = '1';matrix[3][3] = '1';
	Solution s;
	cout << s.maximalSquare(matrix) << endl;
	return 0;
}