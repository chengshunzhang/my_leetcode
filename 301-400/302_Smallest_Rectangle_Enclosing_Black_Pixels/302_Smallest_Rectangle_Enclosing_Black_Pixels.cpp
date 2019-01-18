#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void DFS(vector<vector<char>>& image, int x, int y, vector<int>& bound,
            vector<vector<bool>>& visited) {
        int m = image.size(), n = image[0].size();
        int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
        for(int i = 0; i < 4; i++) {
            int new_x = x + dx[i], new_y = y + dy[i];
            if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n &&
               image[new_x][new_y] == '1' && !visited[new_x][new_y]) {
                visited[new_x][new_y] = true;
                if(new_x < bound[0]) {
                    bound[0] = new_x;
                }
                if(new_x > bound[1]) {
                    bound[1] = new_x;
                }
                if(new_y < bound[2]) {
                    bound[2] = new_y;
                }
                if(new_y > bound[3]) {
                    bound[3] = new_y;
                }
                DFS(image, new_x, new_y, bound, visited);
            }
        }
    }
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        vector<int> bound = {x, x, y, y};
        vector<vector<bool>> visited(image.size(), vector<bool> (image[0].size(), false));
        visited[x][y] = true;
        DFS(image, x, y, bound, visited);
        return (bound[1] - bound[0] + 1) * (bound[3] - bound[2] + 1);
    }
};

int main() {
	vector<vector<char>> image = {{'0', '0', '1', '0'},
									{'0', '1', '1', '0'},
									{'0','1', '0', '0'}};
	int x = 0, y = 2;
	Solution s;
	cout << s.minArea(image, x, y) << endl;
	return 0;
}