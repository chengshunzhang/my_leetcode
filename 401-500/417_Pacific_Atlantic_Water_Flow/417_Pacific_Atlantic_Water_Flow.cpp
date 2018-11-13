#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
private:
    void BFS(vector<vector<int> >& matrix, vector<vector<bool> >& visited, queue<pair<int, int> >& q) {
        int m = matrix.size(), n = matrix[0].size();
        pair<int, int> offset[] = {make_pair(0, -1), make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0)};
        while(!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int x = temp.first + offset[i].first, y = temp.second + offset[i].second;
                if(x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && matrix[x][y] >= matrix[temp.first][temp.second]) {
                    q.push(make_pair(x, y));
                    visited[x][y] = true;
                }
            }
        }
    }
public:
    vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
        vector<pair<int, int> > result;
        if(matrix.empty() || matrix[0].empty()) {
            return result;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool> > pacific(m, vector<bool> (n, false)), atlantic(m, vector<bool> (n, false));
        queue<pair<int, int> > q_pacific, q_atlantic;
        for(int i = 0; i < m; i++) {
            pacific[i][0] = true;
            atlantic[i][n - 1] = true;
            q_pacific.push(make_pair(i, 0));
            q_atlantic.push(make_pair(i, n - 1));
        }
        for(int j = 0; j < n; j++) {
            pacific[0][j] = true;
            atlantic[m - 1][j] = true;
            q_pacific.push(make_pair(0, j));
            q_atlantic.push(make_pair(m - 1, j));
        }
        BFS(matrix, pacific, q_pacific);
        BFS(matrix, atlantic, q_atlantic);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back(make_pair(i, j));
                }
            }
        }
        return result;
    }
};

int main() {
    int n[][5] = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int> > matrix;
    for(int i = 0; i < 5; i++) {
        vector<int> temp(n[i],n[i]+5);
        matrix.push_back(temp);
    }
    Solution s;
    vector<pair<int, int> > res = s.pacificAtlantic(matrix);
    for(int i = 0; i < res.size(); i++) {
        cout << '(' << res[i].first << ',' << res[i].second << ')' << ' ';
    }
    cout << endl;
	return 0;
}