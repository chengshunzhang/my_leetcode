#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int> >& maze, vector<int>& start, vector<int>& destination) {
        if(maze.empty() || maze[0].empty()) {
            return false;
        }
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool> > visited(m, vector<bool> (n, false));
        queue<pair<int, int> > q;
        pair<int, int> dest = make_pair(destination[0], destination[1]);
        q.push(make_pair(start[0], start[1]));
        visited[start[0]][start[1]] = true;
        int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
        while(!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int row = temp.first + dx[i], col = temp.second + dy[i];
                while(row >= 0 && row < m && col >= 0 && col < n && maze[row][col] == 0) {
                    row += dx[i];
                    col += dy[i];
                }
                row -= dx[i];
                col -= dy[i];
                if(make_pair(row, col) == dest) {
                    return true;
                }
                if(make_pair(row, col) != temp && !visited[row][col]) {
                    q.push(make_pair(row, col));
                    visited[row][col] = true;
                }
            }
        }
        return false;
    }
};

int main() {
	vector<vector<int> > maze(5, vector<int> (5, 0));
	maze[0][2] = 1;
	maze[2][3] = 1;
	maze[3][0] = maze[3][1] = maze[3][3] = maze[3][4] = 1;
	int sta[] = {0, 4}, d[] = {4, 4};
	vector<int> start(sta,sta+2), destination(d,d+2);
	Solution s;
	cout << s.hasPath(maze, start, destination) << endl;
	return 0;
}