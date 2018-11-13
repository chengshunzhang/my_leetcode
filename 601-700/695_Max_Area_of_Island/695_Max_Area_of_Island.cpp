#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int calculateArea(vector<vector<int> >& grid, int row, int col) {
        int area = 1;
        grid[row][col] = -1;
        int up = row - 1, down = row + 1, left = col - 1, right = col + 1;
        if(row > 0 && grid[up][col] == 1) {
            area += calculateArea(grid, up, col);
        }
        if(down < grid.size() && grid[down][col] == 1) {
            area += calculateArea(grid, down, col);
        }
        if(col > 0 && grid[row][left] == 1) {
            area += calculateArea(grid, row, left);
        }
        if(right < grid[0].size() && grid[row][right] == 1) {
            area += calculateArea(grid, row, right);
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        if(grid.empty()) {
            return 0;
        }
        int result = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    int area = calculateArea(grid, i, j);
                    if(area > result) {
                        result = area;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
	vector<vector<int> > grid(3, vector<int> (3, 1));
	grid[0][0] = 0;
	grid[1][2] = 0;
	Solution s;
	cout << s.maxAreaOfIsland(grid) << endl;
	return 0;
}