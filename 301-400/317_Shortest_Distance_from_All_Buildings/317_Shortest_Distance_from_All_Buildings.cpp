#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
private:
    int BFS(vector<vector<int> >& grid, int row, int col, int& land, vector<vector<int> >& distances) {
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
        queue<pair<int, int> > q;
        q.push(make_pair(row, col));
        q.push(make_pair(-1, -1));
        int dist = 1, result = INT_MAX;
        while(q.size() > 1) {
            pair<int, int> temp = q.front();
            q.pop();
            if(temp == make_pair(-1, -1)) {
                dist++;
                q.push(make_pair(-1, -1));
            } else {
                int row = temp.first, col = temp.second;
                for(int i = 0; i < 4; i++) {
                    int newRow = row + dy[i], newCol = col + dx[i];
                    if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == land) {
                        grid[newRow][newCol] = land - 1;
                        q.push(make_pair(newRow, newCol));
                        distances[newRow][newCol] += dist;
                        if(distances[newRow][newCol] < result) {
                            result = distances[newRow][newCol];
                        }
                    }
                }
            }
        }
        land--;
        return result == INT_MAX ? -1 : result;
    }
public:
    int shortestDistance(vector<vector<int> >& grid) {
        vector<vector<int> > distances(grid.size(), vector<int> (grid[0].size(), 0));
        int result = INT_MAX, land = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    result = BFS(grid, i, j, land, distances);
                    if(result == INT_MAX) {
                        return -1;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
	vector<vector<int> > grid(3, vector<int> (5, 0));
	grid[0][0] = grid[0][4] = grid[2][2] = 1;
	grid[0][2] = 2;
	Solution s;
	cout << s.shortestDistance(grid) << endl;
	return 0;
}