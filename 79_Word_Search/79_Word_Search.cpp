#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    private:
    bool helper(vector<vector<char> >& board, string word, int row, int col, int pos) {
        if(pos == word.size()) {
            return true;
        }
        char temp = board[row][col];
        board[row][col] = ' ';
        if(row > 0 && board[row - 1][col] == word[pos] && helper(board, word, row - 1, col, pos + 1)) {
            return true;
        }
        if(row + 1 < board.size() && board[row + 1][col] == word[pos] && helper(board, word, row + 1, col, pos + 1)) {
            return true;
        }
        if(col > 0 && board[row][col - 1] == word[pos] && helper(board, word, row, col - 1, pos + 1)) {
            return true;
        }
        if(col + 1 < board[0].size() && board[row][col + 1] == word[pos] && helper(board, word, row, col + 1, pos + 1)) {
            return true;
        }
        board[row][col] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char> >& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0] && helper(board, word, i, j, 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
	Solution s;
	vector<vector<char> > board;
	char ch[] = {'A', 'B', 'C', 'E'};
	vector<char> chars(ch, ch + 4);
	board.push_back(chars);
	chars[0] = 'S'; chars[1] = 'F'; chars[2] = 'C'; chars[3] = 'S';
	board.push_back(chars);
	chars[0] = 'A'; chars[1] = 'D'; chars[2] = 'E'; chars[3] = 'E';
	board.push_back(chars);
	cout << s.exist(board, "ABCCED") << endl;
	return 0;
}