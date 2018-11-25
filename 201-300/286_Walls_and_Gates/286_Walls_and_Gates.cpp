#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int> >& rooms) {
        if(rooms.empty() || rooms[0].empty()) {
            return;
        }
        int m = rooms.size(), n = rooms[0].size(), drow[] = {-1, 0, 1, 0}, dcol[] = {0, -1, 0, 1};
        queue<pair<int, int> > q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rooms[i][j] == 0) {
                    q.push(make_pair(i, j));
                }
            }
        }
        q.push(make_pair(-1, -1));
        vector<vector<int> > visited(m, vector<int> (n, false));
        int dist = 1;
        while(q.size() > 1) {
            pair<int, int> temp = q.front();
            q.pop();
            if(temp == make_pair(-1, -1)) {
                dist++;
                q.push(make_pair(-1, -1));
            } else {
                for(int k = 0; k < 4; k++) {
                    int row = temp.first + drow[k], col = temp.second + dcol[k];
                    if(row >= 0 && row < m && col >= 0 && col < n && rooms[row][col] > 0 && !visited[row][col]) {
                        q.push(make_pair(row, col));
                        visited[row][col] = true;
                        rooms[row][col] = dist;
                    }
                }
            }
        }
    }
};

int main() {
	vector<vector<int> > grid(4, vector<int> (4, INT_MAX));
	grid[0][1] = grid[1][3] = grid[2][1] = grid[2][3] = grid[3][1] = -1;
	grid[0][2] = grid[3][0] = 0;
	Solution s;
	s.wallsAndGates(grid);
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[0].size(); j++) {
			cout << grid[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}