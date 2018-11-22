#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int findNum(vector<vector<int> >& matrix, int mid) {
        int row = matrix.size() - 1, col = 0, result = 0;
        while(row >= 0 && col < matrix[0].size()) {
            if(matrix[row][col] > mid) {
                row--;
            } else {
                col++;
                result += row + 1;
            }
        }
        return result;
    }
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        int min = matrix[0][0], max = matrix.back().back();
        while(min + 1 < max) {
            int mid = min + (max - min) / 2;
            int num = findNum(matrix, mid);
            if(num < k) {
                min = mid;
            } else {
                max = mid;
            }
        }
        int num = findNum(matrix, min);
        if(num < k) {
            return max;
        } else {
            return min;
        }
    }
};

int main() {
	vector<vector<int> > matrix(2, vector<int> (2));
	matrix[0][0] = 1; matrix[0][1] = 2;
	matrix[1][0] = matrix[1][1] = 3;
	int k = 4;
	Solution s;
	cout << s.kthSmallest(matrix, k) << endl;
	return 0;
}