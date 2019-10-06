#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), na = A[0].size(), mb = B.size(), n = B[0].size();
        vector<vector<int>> result(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < na; j++) {
                for(int k = 0; k < n; k++) {
                    if(A[i][j] != 0 && B[j][k] != 0) {
                        result[i][k] += A[i][j] * B[j][k];
                    }
                }
            }
        }
        return result;
    }
};

int main() {
	vector<vector<int>> A = {{-1, 0, 0}, {-1, 0, 3}}, B = {{7, 0, 0}, {0, 0, 0}, {0, 0, 1}};
	Solution sol;
	vector<vector<int>> result = sol.multiply(A, B);
	for(int i = 0; i < result.size(); i++) {
		for(int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ',';
		}
		cout << "\b " << endl;
	}
	return 0;
}