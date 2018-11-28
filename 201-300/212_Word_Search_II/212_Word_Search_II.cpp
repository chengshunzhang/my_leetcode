#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct TrieNode {
    bool haveWord;
    vector<TrieNode*> next;
    TrieNode() : haveWord(false) {
        next.resize(26);
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

class Solution {
private:
    void DFS(vector<vector<char> >& board, vector<vector<bool> >& visited, int row, int col, TrieNode* ptr, string& temp, unordered_set<string>& result) {
        int m = board.size(), n = board[0].size();
        visited[row][col] = true;
        temp.push_back(board[row][col]);
        if(ptr -> haveWord) {
            result.insert(temp);
        }
        int drow[] = {-1, 0, 1, 0}, dcol[] = {0, -1, 0, 1};
        for(int i = 0; i < 4; i++) {
            int nRow = row + drow[i], nCol = col + dcol[i];
            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && ptr -> next[board[nRow][nCol] - 'a']  && !visited[nRow][nCol]) {
                DFS(board, visited, nRow, nCol, ptr -> next[board[nRow][nCol] - 'a'], temp, result);
            }
        }
        temp.pop_back();
        visited[row][col] = false;
    }
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        TrieNode* root = new TrieNode;
        unordered_set<string> result;
        if(board.empty() || board[0].empty()) {
            return vector<string> ();
        }
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < words.size(); i++) {
            TrieNode* p = root;
            for(int j = 0; j < words[i].size(); j++) {
                if(p -> next[words[i][j] - 'a'] == NULL) {
                    p -> next[words[i][j] - 'a'] = new TrieNode;
                }
                p = p -> next[words[i][j] - 'a'];
            }
            p -> haveWord = true;
        }
        vector<vector<bool> > visited(m, vector<bool> (n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(root -> next[board[i][j] - 'a']) {
                    string temp = "";
                    DFS(board, visited, i, j, root -> next[board[i][j] - 'a'], temp, result);
                } 
            }
        }
        return vector<string> (result.begin(), result.end());
    }
};

int main() {
	string w[] = {"oath", "pea", "eat", "rain"};
	vector<string> words(w,w+4);
	vector<vector<char> > board(4, vector<char> (4));
	board[0][0] = 'o';
	board[0][1] = board[0][2] = board[1][2] = 'a';
	board[0][3] = 'n';
	board[1][0] = board[1][3] = 'e';
	board[1][1] = 't';
	board[2][0] = board[3][0] = 'i';
	board[2][1] = 'h';
	board[2][2] = 'k';
	board[2][3] = 'r';
	board[3][1] = 'f';
	board[3][2] = 'l';
	board[3][3] = 'v';
	Solution s;
	vector<string> res = s.findWords(board, words);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ',';
	}
	cout << "\b \b" << endl;
	return 0;
}