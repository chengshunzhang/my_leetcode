#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
private:
    int n, remain, n_rows, n_cols;
    unordered_map<int, int> hash;
public:
    Solution(int n_rows, int n_cols) {
        n = n_rows * n_cols;
        remain = n;
        this -> n_rows = n_rows;
        this -> n_cols = n_cols;
    }
    
    vector<int> flip() {
        int id = rand() % remain, pos;
        if(!hash.count(id)) {
            pos = id;
        } else {
            pos = hash[id];
        }
        if(!hash.count(remain - 1)) {
            hash[id] = remain - 1;
        } else {
            hash[id] = hash[remain - 1];
        }
        remain--;
        int row = pos / n_cols, col = pos % n_cols;
        vector<int> result(2);
        result[0] = row;
        result[1] = col;
        return result;
    }
    
    void reset() {
        remain = n;
        hash.clear();
    }
};

int main() {
	int n_rows = 2, n_cols = 2;
	Solution s(n_rows, n_cols);
	vector<int> res = s.flip();
	cout << res[0] << ',' << res[1] << endl;
	res = s.flip();
	cout << res[0] << ',' << res[1] << endl;
	res = s.flip();
	cout << res[0] << ',' << res[1] << endl;
	res = s.flip();
	cout << res[0] << ',' << res[1] << endl;
	return 0;
}