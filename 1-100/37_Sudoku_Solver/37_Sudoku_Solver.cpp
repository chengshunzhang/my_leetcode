#include <vector>
#include <iostream>
using namespace std;

struct grid {
	int val;
	int row;
	int col;
	int block;
	grid(int v, int r, int c, int b): val(v), row(r), col(c), block(b) {}
};

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        vector<grid> grids;
        bool row[9][9] = {false}, col[9][9] = {false}, block[9][9] = {false};
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                int block_num = i / 3 * 3 + j / 3;
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    row[i][num] = col[j][num] = block[block_num][num] = true;
                } else {
                    grids.push_back(grid(1, i, j, block_num));
                }
            }
        }
        int p = 0, n = grids.size();
        while(p < n) {
            int num = grids[p].val - 1;
            if(row[grids[p].row][num] || col[grids[p].col][num] || block[grids[p].block][num]) {
                while(grids[p].val == 9) {
                    grids[p--].val = 1;
                    num = grids[p].val - 1;
                    row[grids[p].row][num] = col[grids[p].col][num] = block[grids[p].block][num] = false;
                }
                grids[p].val++;
            } else {
                row[grids[p].row][num] = col[grids[p].col][num] = block[grids[p].block][num] = true;
                p++;
            }
        }
        for(int i = 0; i < n; i++) {
            board[grids[i].row][grids[i].col] = grids[i].val + '0';
        }
    }
};

int main() {
	Solution s;
	vector<vector<char> > board(9, vector<char> (9, '.'));
	board[0][0] = '5'; board[0][1] = '3'; board[0][4] = '7'; 
	board[1][0] = '6'; board[1][3] = '1'; board[1][4] = '9'; board[1][5] = '5';
	board[2][1] = '9'; board[2][2] = '8'; board[2][7] = '6';
	board[3][0] = '8'; board[3][4] = '6'; board[3][8] = '3';
	board[4][0] = '4'; board[4][3] = '8'; board[4][5] = '3'; board[4][8] = '1';
	board[5][0] = '7'; board[5][4] = '2'; board[5][8] = '6';
	board[6][1] = '6'; board[6][6] = '2'; board[6][7] = '8';
	board[7][3] = '4'; board[7][4] = '1'; board[7][5] = '9'; board[7][8] = '5';
	board[8][4] = '8'; board[8][7] = '7'; board[8][9] = '9';
	s.solveSudoku(board);
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}