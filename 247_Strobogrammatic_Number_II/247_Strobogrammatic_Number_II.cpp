#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    void findHelper(vector<string>& result, string& temp, int n, int pos) {
        if(n % 2 == 0 && pos == n / 2) {
            result.push_back(temp);
            return;
        }
        if(n % 2 == 1 && pos == n / 2 + 1) {
            result.push_back(temp);
            return;
        }
        int sym = n - 1 - pos;
        temp[pos] = temp[sym] = '1';
        findHelper(result, temp, n, pos + 1);
        temp[pos] = temp[sym] = '8';
        findHelper(result, temp, n, pos + 1);
        if(pos != sym) {
            temp[pos] = '6';
            temp[sym] = '9';
            findHelper(result, temp, n, pos + 1);
        }
        if(pos != sym) {
            temp[pos] = '9';
            temp[sym] = '6';
            findHelper(result, temp, n, pos + 1);
        }
        if(pos != 0) {
            temp[pos] = temp[n - 1 - pos] = '0';
            findHelper(result, temp, n, pos + 1);
        }
    }
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> result;
        if(n == 0) {
            return result;
        }
        if(n == 1) {
            result.push_back("0");
        }
        string temp(n, '1');
        findHelper(result, temp, n, 0);
        return result;
    }
};

int main() {
	Solution s;
	vector<string> res = s.findStrobogrammatic(2);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}