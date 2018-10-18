#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        if(input.empty()) {
            return result;
        }
        vector<int> operations;
        for(int i = 0; i < input.size(); i++) {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
                operations.push_back(i);
            }
        }
        if(operations.empty()) {
            result.push_back(atoi(input.c_str()));
            return result;
        } else {
            for(int i = 0; i < operations.size(); i++) {
                vector<int> left = diffWaysToCompute(input.substr(0, operations[i]));               
                vector<int> right = diffWaysToCompute(input.substr(operations[i] + 1));
                for(int l = 0; l < left.size(); l++) {
                    for(int r = 0; r < right.size(); r++) {
                        if(input[operations[i]] == '+') {
                            result.push_back(left[l] + right[r]);
                        } else if(input[operations[i]] == '-') {
                            result.push_back(left[l] - right[r]);
                        } else {
                            result.push_back(left[l] * right[r]);
                        }
                    }
                }
            }
            return result;
        }
    }
};

int main() {
	string input("2*3-4*5");
	Solution s;
	vector<int> res = s.diffWaysToCompute(input);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}
