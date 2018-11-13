#include <vector>
#include <iostream>
using namespace std;

class Solution {
    private:
    void helper(vector<vector<char> >& result, int row, int col) {
        int mines = 0;
        vector<pair<int, int> > positions;
        if(row > 0 && col > 0) {
            if(result[row - 1][col - 1] == 'M') {
                mines++;
            } else if(result[row - 1][col - 1] == 'E'){
                positions.push_back(make_pair(row - 1, col - 1));
            }
        }
        if(row > 0) {
            if(result[row - 1][col] == 'M') {
                mines++;
            } else if(result[row - 1][col] == 'E'){
                positions.push_back(make_pair(row - 1, col));
            }
        }
        if(row > 0 && col + 1 < result[0].size()) {
            if(result[row - 1][col + 1] == 'M') {
                mines++;
            } else if(result[row - 1][col + 1] == 'E'){
                positions.push_back(make_pair(row - 1, col + 1));
            }
        }
        if(col > 0) {
            if(result[row][col - 1] == 'M') {
                mines++;
            } else if(result[row][col - 1] == 'E'){
                positions.push_back(make_pair(row, col - 1));
            }
        }
        if(col + 1 < result[0].size()) {
            if(result[row][col + 1] == 'M') {
                mines++;
            } else if(result[row][col + 1] == 'E'){
                positions.push_back(make_pair(row, col + 1));
            }
        }
        if(row + 1 < result.size() && col > 0) {
            if(result[row + 1][col - 1] == 'M') {
                mines++;
            } else if(result[row + 1][col - 1] == 'E'){
                positions.push_back(make_pair(row + 1, col - 1));
            }
        }
        if(row + 1 < result.size()) {
            if(result[row + 1][col] == 'M') {
                mines++;
            } else if(result[row + 1][col] == 'E'){
                positions.push_back(make_pair(row + 1, col));
            }
        }
        if(row + 1 < result.size() && col + 1 < result[0].size()) {
            if(result[row + 1][col + 1] == 'M') {
                mines++;
            } else if(result[row + 1][col + 1] == 'E'){
                positions.push_back(make_pair(row + 1, col + 1));
            }
        }
        if(mines > 0) {
            result[row][col] = mines + '0';
        } else {
            result[row][col] = 'B';
            for(int i = 0; i < positions.size(); i++) {
                result[positions[i].first][positions[i].second] = 'P';
            }
            for(int i = 0; i < positions.size(); i++) {
                helper(result, positions[i].first, positions[i].second);
            }
        }
    }
public:
    vector<vector<char> > updateBoard(vector<vector<char> >& board, vector<int>& click) {
        vector<vector<char> > result(board);
        if(result[click[0]][click[1]] == 'M') {
            result[click[0]][click[1]] = 'X';
            return result;
        } else {
            helper(result, click[0], click[1]);
            return result;
        }
    }
};

int main() {
	vector<vector<char> > board(4, vector<char> (5, 'E'));
	board[1][2] = 'M';
	vector<int> click(2);
	click[0] = 3;
	click[1] = 0;
	Solution s;
	vector<vector<char> > res = s.updateBoard(board, click);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}