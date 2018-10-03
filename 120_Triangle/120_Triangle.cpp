#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int n = triangle.size();
        if(n == 0) {
            return 0;
        }
        vector<vector<int> > A;
        A.push_back(triangle[0]);
        for(int i = 1; i < n; i++) {
            vector<int> temp(1, A[i - 1][0] + triangle[i][0]);
            for(int j = 1; j < i; j++) {
                int cur = (A[i - 1][j - 1] < A[i - 1][j] ? triangle[i][j] + A[i - 1][j - 1] : triangle[i][j] + A[i - 1][j]);
                temp.push_back(cur);
            }
            temp.push_back(triangle[i][i] + A[i - 1][i - 1]);
            A.push_back(temp);
        }
        int min = A[n - 1][0];
        for(int i = 1; i < n; i++) {
            if(A[n - 1][i] < min) {
                min = A[n - 1][i];
            }
        }
        return min;
    }
};

int main() {
	vector<vector<int> > triangle(4);
	triangle[0].push_back(2);
	triangle[1].push_back(3); triangle[1].push_back(4);
	triangle[2].push_back(6); triangle[2].push_back(5); triangle[2].push_back(7);
	triangle[3].push_back(4); triangle[3].push_back(1); triangle[3].push_back(8); triangle[3].push_back(3);
	Solution s;
	cout << s.minimumTotal(triangle) << endl;
	return 0;
}