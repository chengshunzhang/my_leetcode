#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        bool row[9][9] = {false}, col[9][9] = {false}, block[9][9] = {false};
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                int block_num = i / 3 * 3 + j / 3, num = board[i][j] - '0' - 1;
                if(row[i][num] || col[j][num] || block[block_num][num]) {
                    return false;
                } else {
                    row[i][num] = col[j][num] = block[block_num][num] = true;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char> > board(9, vector<char> (9, '.'));
    board[0][0] = '8', board[0][1] = '3', board[2][1] = 6;
    Solution s;
    cout << s.isValidSudoku(board) << endl;
    return 0;
}