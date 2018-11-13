#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    private:
    pair<int, int> getPosition(int num, int n) {
        int normalRow = (num - 1) / n, normalCol = (num - 1) % n;
        int row = n - 1 - normalRow, col = normalRow % 2 == 0 ? normalCol : n - 1 - normalCol;
        return make_pair(row, col);
    }
public:
    int snakesAndLadders(vector<vector<int> >& board) {
        int n = board.size(), maxNum = n * n;
        vector<bool> visited(maxNum, false);
        queue<int> q;
        q.push(1);
        q.push(-1);
        visited[0] = true;
        int count = 0;
        while(q.size() > 1) {
            int cur = q.front();
            q.pop();
            if(cur == -1) {
                count++;
                q.push(-1);
            } else {
                for(int i = 1; i <= 6; i++) {
                    int destNum = cur + i;
                    pair<int, int> temp = getPosition(destNum, n);
                    if(destNum == maxNum) {
                        return count + 1;
                    }
                    if(!visited[destNum - 1] || board[temp.first][temp.second] != -1) {
                        visited[destNum - 1] = true;
                        if(board[temp.first][temp.second] == -1){
                            q.push(destNum);
                        } else if(!visited[board[temp.first][temp.second] - 1]){
                            if(board[temp.first][temp.second] == maxNum) {
                                return count + 1;
                            }
                            q.push(board[temp.first][temp.second]);
                            visited[board[temp.first][temp.second] - 1] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
	int n = 6;
	vector<vector<int> > board(n, vector<int> (n, -1));
	board[3][1] = 35;
	board[3][4] = 13;
	board[5][1] = 15;
	Solution s;
	cout << s.snakesAndLadders(board) << endl;
	return 0;
}