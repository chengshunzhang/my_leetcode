#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<int> unroll(m * n);
        int k = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                unroll[k++] = matrix[i][j];
            }
        }
        int left = 0, right = unroll.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(unroll[mid] == target) {
                return true;
            } else if(unroll[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

int main() {
	vector<vector<int> > matrix(3, vector<int> (4));
	matrix[0][0] = 1; matrix[0][1] = 3; matrix[0][2] = 5; matrix[0][3] = 7;
	matrix[1][0] = 10; matrix[1][1] = 11; matrix[1][2] = 16; matrix[1][3] = 20;
	matrix[2][0] = 23; matrix[2][1] = 30; matrix[2][2] = 34; matrix[2][3] = 50;
	Solution s;
	int target = 3;
	cout << s.searchMatrix(matrix, target) << endl;
	return 0;
}