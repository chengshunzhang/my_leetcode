#include <vector>
#include <iostream>
using namespace std;

class TicTacToe {
private:
    vector<int> rownum, colnum;
    int size, main, sub;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        size = n;
        rownum.resize(n, 0);
        colnum.resize(n, 0);
        main = sub = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int temp = size - 1 - col, add = (player == 1 ? 1 : -1);
        rownum[row] += add;
        if(abs(rownum[row]) == size) {
            return player;
        }
        colnum[col] += add;
        if(abs(colnum[col]) == size) {
            return player;
        }
        if(row == col) {
            main += add;
            if(abs(main) == size) {
                return player;
            }
        }
        if(row == temp) {
            sub += add;
            if(abs(sub) == size) {
                return player;
            }
        }
        return 0;
    }
};

int main() {
	TicTacToe toe(3);
	cout << toe.move(0, 0, 1) << endl;
	cout << toe.move(0, 2, 2) << endl;
	cout << toe.move(2, 2, 1) << endl;
	cout << toe.move(1, 1, 2) << endl;
	cout << toe.move(2, 0, 1) << endl;
	cout << toe.move(1, 0, 2) << endl;
	cout << toe.move(2, 1, 1) << endl;
	return 0;
}