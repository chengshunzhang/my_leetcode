#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int> (n));
        int i = 1;
        for(int layer = 0; layer < (n + 1) / 2; layer++) {
            int edge = n - 1 - layer;
            for(int col = layer; col < edge; col++) {
                result[layer][col] = i++;
            }
            for(int row = layer; row < edge; row++) {
                result[row][edge] = i++;
            }
            for(int col = edge; col > layer; col--) {
                result[edge][col] = i++;
            }
            for(int row = edge; row > layer; row--) {
                result[row][layer] = i++;
            }
        }
        if(n % 2 == 1) {
            result[n / 2][n / 2] = i;
        }
        return result;
    }
};

int main() {
	Solution s;
	vector<vector<int> > res;
	res = s.generateMatrix(3);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}