#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        if(board.empty() || board[0].empty()) {
            return; // 2: originally live, now dead; 3: originally dead, now live;
        }
        int m = board.size(), n = board[0].size();
        int drow[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dcol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for(int i = 0; i < m; i++) { 
            for(int j = 0; j < n; j++) {
                int lives = 0;
                for(int k = 0; k < 8; k++) {
                    int neighborRow = i + drow[k], neighborCol = j + dcol[k];
                    if(neighborRow >= 0 && neighborRow < m && neighborCol >= 0 && neighborCol < n && (board[neighborRow][neighborCol] == 1 || board[neighborRow][neighborCol] == 2)) {
                        lives++;
                    }
                }
                if(lives < 2 && board[i][j] == 1) {
                    board[i][j] = 2;
                }
                if(lives > 3 && board[i][j] == 1) {
                    board[i][j] = 2;
                }
                if(lives == 3 && board[i][j] == 0) {
                    board[i][j] = 3;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 2) {
                    board[i][j] = 0;
                }
                if(board[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};

int main() {
	vector<vector<int> > board(4, vector<int> (3, 0));
	board[0][1] = board[1][2] = board[2][0] = board[2][1] = board[2][2] = 1;
	Solution s;
	s.gameOfLife(board);
	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[0].size(); j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}