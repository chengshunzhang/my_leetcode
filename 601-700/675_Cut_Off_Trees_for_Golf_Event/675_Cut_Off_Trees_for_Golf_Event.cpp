#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
    private:
    int BFS(vector<vector<int> >& forest, pair<int, int> start, pair<int, int> dest) {
        pair<int, int> offset[] = {make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};
        vector<vector<bool> > visited(forest.size(), vector<bool> (forest[0].size(), false));
        int steps = 0;
        queue<pair<int, int> > q;
        q.push(start);
        q.push(make_pair(-1, -1));
        visited[start.first][start.second] = true;
        while(q.size() > 1) {
            pair<int, int> temp = q.front();
            q.pop();
            if(temp == pair<int, int> (-1, -1)) {
                steps++;
                q.push(make_pair(-1, -1));
            } else {
                for(int i = 0; i < 4; i++) {
                    int row = temp.first + offset[i].first, col = temp.second + offset[i].second;
                    if(make_pair(row, col) == dest) {
                        return steps + 1;
                    }
                    if(row >= 0 && row < forest.size() && col >= 0 && col < forest[0].size() && forest[row][col] && !visited[row][col]) {
                        q.push(make_pair(row, col));
                        visited[row][col] = true;
                    }
                }
            }
        }
        return -1;
    }
public:
    int cutOffTree(vector<vector<int> >& forest) {
        int result = 0;
        vector<vector<int> > heights;
        for(int i = 0; i < forest.size(); i++) {
            for(int j = 0; j < forest[0].size(); j++) {
                if(forest[i][j] > 1) {
                    int h[] = {forest[i][j], i, j};
                    heights.push_back(vector<int> (h, h + 3));
                }
            }
        }
        sort(heights.begin(), heights.end());
        pair<int, int> start = make_pair(0, 0);
        for(int i = 0; i < heights.size(); i++) {
            pair<int, int> dest = make_pair(heights[i][1], heights[i][2]);
            if(dest == start) {
                continue;
            }
            int step = BFS(forest, start, dest);
            if(step == -1) {
                return -1;
            }
            result += step;
            start = dest;
        }
        return result;
    }
};

int main() {
	vector<vector<int> > forest;
	int h[][3] = {{1,2,3},{0,0,4},{7,6,5}};
	for(int i = 0; i < 3; i++) {
		forest.push_back(vector<int> (h[i],h[i]+3));
	}
	Solution s;
	cout << s.cutOffTree(forest) << endl;
	return 0;
}