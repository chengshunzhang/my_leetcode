#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        if(matrix.empty()) {
            return;
        }
        int n = matrix.size();
        for(int layer = 0; layer < n / 2; layer++) {
            int times = n - 2 * layer - 1;
            for(int i = 0; i < times; i++) {
                int first_col = layer + i, second_col = n - 1 - layer, third_col = n - 1 - layer - i;
                int first = matrix[layer][first_col];
                int second = matrix[first_col][second_col];
                int third = matrix[second_col][third_col];
                int fourth = matrix[third_col][layer];
                matrix[layer][first_col] = fourth;
                matrix[first_col][second_col] = first;
                matrix[second_col][third_col] = second;
                matrix[third_col][layer] = third;
            }
        }
    }
};

int main() {
	vector<vector<int> > matrix(3);
	matrix[0].push_back(1);matrix[0].push_back(2);matrix[0].push_back(3);
	matrix[1].push_back(4);matrix[1].push_back(5);matrix[1].push_back(6);
	matrix[2].push_back(7);matrix[2].push_back(8);matrix[2].push_back(9);
	Solution s;
	s.rotate(matrix);
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}