#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    void DFS(vector<vector<int> >& grid, int row, int col, string& shape) {
        grid[row][col] = 2;
        pair<int, int> offset[] = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};
        char direction[] = {'r', 'u', 'l', 'd'};
        for(int i = 0; i < 4; i++) {
            int newRow = row + offset[i].second, newCol = col + offset[i].first;
            if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1) {
                shape.push_back(direction[i]);
                DFS(grid, newRow, newCol, shape);
                shape.push_back(',');
            }
        }
    }
public:
    int numDistinctIslands(vector<vector<int> >& grid) {
        if(grid.empty() || grid[0].empty()) {
            return 0;
        }
        unordered_map<string, bool> hash;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    string shape = "";
                    DFS(grid, i, j, shape);
                    if(!hash.count(shape)) {
                        hash[shape] = true;
                    }
                }                
            }
        }
        return hash.size();
    }
};

int main() {
	vector<vector<int> > grid(4, vector<int> (5, 0));
	grid[0][0] = grid[0][1] = 1;
	grid[1][0] = grid[1][1] = 1;
	grid[2][3] = grid[2][4] = 1;
	grid[3][3] = grid[3][4] = 1;
	Solution s;
	cout << s.numDistinctIslands(grid) << endl;
	return 0;
}