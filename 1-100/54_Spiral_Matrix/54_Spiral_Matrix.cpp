#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        if(matrix.empty()) {
            return result;
        }
        int direct = 0, m = matrix.size(), n = matrix[0].size(), count = 0;
        vector<int> edge(4);
        edge[0] = -1, edge[1] = n, edge[2] = m, edge[3] = -1;
        while(count < m * n) {
            if(direct == 0) {
                for(int i = edge[3] + 1; i < edge[1]; i++) {
                    result.push_back(matrix[edge[0] + 1][i]);
                    count++;
                }
                direct = 1;
                edge[0]++;
            } else if(direct == 1) {
                for(int i = edge[0] + 1; i < edge[2]; i++) {
                    result.push_back(matrix[i][edge[1] - 1]);
                    count++;
                }
                direct = 2;
                edge[1]--;
            } else if(direct == 2) {
                for(int i = edge[1] - 1; i > edge[3]; i--) {
                    result.push_back(matrix[edge[2] - 1][i]);
                    count++;
                }
                direct = 3;
                edge[2]--;
            } else {
                for(int i = edge[2] - 1; i > edge[0]; i--) {
                    result.push_back(matrix[i][edge[3] + 1]);
                    count++;
                }
                direct = 0;
                edge[3]++;
            }
        }
        return result;
    }
};

int main() {
	int n[][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	vector<vector<int> > matrix(3, vector<int> (4));
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[0].size(); j++) {
			matrix[i][j] = n[i][j];
		}
	}
	Solution s;
	vector<int> res = s.spiralOrder(matrix);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}