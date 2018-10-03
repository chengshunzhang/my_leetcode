#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row1(1, 1), row2;
        bool flag = 0;
        if(rowIndex == 0) {
            return row1;
        }
        for(int i = 1; i <= rowIndex; i++) {
            if(flag == 0) {
                row2.push_back(1);
                for(int j = 1; j < i; j++) {
                    row2.push_back(row1[j - 1] + row1[j]);
                }
                row2.push_back(1);
                row1.clear();
                flag = 1;
            } else {
                row1.push_back(1);
                for(int j = 1; j < i; j++) {
                    row1.push_back(row2[j - 1] + row2[j]);
                }
                row1.push_back(1);
                row2.clear();
                flag = 0;
            }
        }
        if(flag == 0) {
            return row1;
        } else {
            return row2;
        }
    }
};

int main() {
	Solution s;
	vector<int> res = s.getRow(5);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}