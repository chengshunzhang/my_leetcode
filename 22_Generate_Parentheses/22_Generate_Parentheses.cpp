#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    private:
    void helper(vector<string>& result, string& temp, int left, int right) {
        if(left > right) {
            return;
        }
        if(left == 0 && right == 0) {
            result.push_back(temp);
            return;
        }
        if(left > 0) {
            temp += '(';
            helper(result, temp, left - 1, right);
            temp.pop_back();
        }
        if(right > 0) {
            temp += ')';
            helper(result, temp, left, right - 1);
            temp.pop_back();
        }  
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp = "";
        helper(result, temp, n, n);
        return result;
    }
};

int main() {
	Solution s;
	vector<string> res = s.generateParenthesis(3);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}