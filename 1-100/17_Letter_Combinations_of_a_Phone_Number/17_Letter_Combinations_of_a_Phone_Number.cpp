#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    void helper(vector<string>& result, vector<vector<char> >& board, string& digits, string& ele, int pos) {
        if(pos == digits.size()) {
            result.push_back(ele);
            return;
        }
        int id = digits[pos] - '2';
        for(int i = 0; i < board[id].size(); i++) {
            ele.push_back(board[id][i]);
            helper(result, board, digits, ele, pos + 1);
            ele.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char> > board(8);
        board[0].push_back('a');
        board[0].push_back('b');
        board[0].push_back('c');
        board[1].push_back('d');
        board[1].push_back('e');
        board[1].push_back('f');
        board[2].push_back('g');
        board[2].push_back('h');
        board[2].push_back('i');
        board[3].push_back('j');
        board[3].push_back('k');
        board[3].push_back('l');
        board[4].push_back('m');
        board[4].push_back('n');
        board[4].push_back('o');
        board[5].push_back('p');
        board[5].push_back('q');
        board[5].push_back('r');
        board[5].push_back('s');
        board[6].push_back('t');
        board[6].push_back('u');
        board[6].push_back('v');
        board[7].push_back('w');
        board[7].push_back('x');
        board[7].push_back('y');
        board[7].push_back('z');
        string ele = "";
        vector<string> result;
        if(digits.empty()) {
            return result;
        }
        helper(result, board, digits, ele, 0);
        return result;
    }
};

int main() {
	Solution s;
	vector<string> res = s.letterCombinations("23");
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}