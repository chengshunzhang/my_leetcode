#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int minimum = INT_MAX, m = maze.size(), n = maze[0].size();
        int dRow[4] = {-1, 0, 1, 0}, dCol[4] = {0, -1, 0, 1};
        vector<vector<int>> visited(m, vector<int> (n, -1));
        visited[start[0]][start[1]] = 0;
        queue<vector<int>> q;
        q.push({start[0], start[1]});
        while(!q.empty()) {
            int row = q.front()[0], col = q.front()[1], curSteps = visited[row][col];
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int newRow = row + dRow[i], newCol = col + dCol[i];
                while(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                     maze[newRow][newCol] == 0) {
                    newRow += dRow[i];
                    newCol += dCol[i];
                }
                newRow -= dRow[i];
                newCol -= dCol[i];
                int s = curSteps + abs(newRow - row) + abs(newCol - col);
                if(newRow == destination[0] && newCol == destination[1]) {
                    if(s < minimum) {
                        minimum = s;
                    }
                } else if(visited[newRow][newCol] == -1 ||
                         visited[newRow][newCol] > s) {
                    visited[newRow][newCol] = s;
                    q.push({newRow, newCol});
                }
            }
            
        }
        if(minimum == INT_MAX) {
            return -1;
        }
        return minimum;
    }
};

int main() {
	vector<vector<int>> maze = {{0, 0, 1, 0, 0},
								{0, 0, 0, 0, 0},
								{0, 0, 0, 1, 0},
								{1, 1, 0, 1, 1},
								{0, 0, 0, 0, 0}};
	vector<int> start = {0, 4}, destination = {4, 4};
	Solution s;
	cout << s.shortestDistance(maze, start, destination) << endl;
	return 0;
}