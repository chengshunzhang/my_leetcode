#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1 || n <= numRows) {
            return s;
        }
        int T = numRows + numRows - 2;
        string result(s);
        int numCols1 = n / T * (numRows - 1), numCols2 = 0, offset = n % T;
        if(offset > 0 && offset <= numRows) {
            numCols2 = 1;
        } else if(offset > numRows){
            numCols2 = offset - numRows + 1;
        }
        int numCols = numCols1 + numCols2;
        vector< vector<char> > zigZag(numRows, vector<char> (numCols, ' '));
        int period_num = 0;
        for(int i = 0; i < n; i++) {
            if(i > 0 && i % T == 0) {
                period_num++;
            }
            int row_pos, col_pos, idx = i - T * period_num;
            if(idx < numRows) {
                row_pos = idx;
                col_pos = (numRows - 1) * period_num;
            } else {
                row_pos = numRows - 1 - (idx - numRows + 1);
                col_pos = (numRows - 1) * period_num + idx - numRows + 1;
            }
            zigZag[row_pos][col_pos] = s[i];
        }
        int result_p = 0;
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < numCols; j++) {
                if(zigZag[i][j] != ' ') {
                    result[result_p++] = zigZag[i][j];
                }
            }
        }
        return result;
    }
};

int main() {
	string s1("hyrqckvnzvzuvpvqodcufxjzrvaxrxsaxjsbvooxlorifmyvsaqxzbzrwzqpykrvvkwsalpnbivgxtcrvuouvn");
	Solution s;
	cout << s.convert(s1, 10) << endl;
	return 0;
}