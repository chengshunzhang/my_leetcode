#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void visit(vector<vector<char> >& grid, int row, int col) {
        grid[row][col] = 2;
        int top = row - 1, right = col + 1, bottom = row + 1, left = col - 1, m = grid.size(), n = grid[0].size();
        if(row > 0 && grid[top][col] == '1') {
            visit(grid, top, col);
        }
        if(row < m - 1 && grid[bottom][col] == '1') {
            visit(grid, bottom, col);
        }
        if(col > 0 && grid[row][left] == '1') {
            visit(grid, row, left);
        }
        if(col < n - 1 && grid[row][right] == '1') {
            visit(grid, row, right);
        }
    }
public:
    int numIslands(vector<vector<char> >& grid) {
        if(grid.empty()) {
            return 0;
        }
        int result = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    visit(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }
};

int main() {
	Solution s;
	vector<vector<char> > grid(4, vector<char> (5, '0'));
	grid[0][0] = grid[0][1] = grid[0][2] = grid[0][3] = grid[1][0] = grid[1][1] = grid[1][3] = grid[2][0] = grid[2][1] = '1';
	cout << s.numIslands(grid) << endl;
	return 0;
}