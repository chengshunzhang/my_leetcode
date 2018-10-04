#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void helper(int r, int c, vector<vector<char> >& board, int& m, int& n) {
        board[r][c] = 'v';
        if(r > 0 && board[r - 1][c] == 'O') {
            helper(r - 1, c, board, m, n);
        }
        if(r < m - 1 && board[r + 1][c] == 'O') {
            helper(r + 1, c, board, m, n);
        }
        if(c > 0 && board[r][c - 1] == 'O') {
            helper(r, c - 1, board, m, n);
        }
        if(c < n - 1 && board[r][c + 1] == 'O') {
            helper(r, c + 1, board, m, n);
        }
    }
public:
    void solve(vector<vector<char> >& board) {
        if(board.empty()) {
            return;
        }
        int m = board.size(), n = board[0].size();
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') {
                helper(0, j, board, m, n);
            }
            if(board[m - 1][j] == 'O') {
                helper(m - 1, j, board, m, n);
            }
        }
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                helper(i, 0, board, m, n);
            }
            if(board[i][n - 1] == 'O') {
                helper(i, n - 1, board, m, n);
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'v') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main() {
	vector<vector<char> > board(4, vector<char>(4, 'X'));
	board[1][1] = board[1][2] = board[2][2] = board[3][1] = 'O';
	Solution s;
	s.solve(board);
	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[0].size(); j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}