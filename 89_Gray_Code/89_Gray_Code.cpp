#include <string>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        unordered_map<string, int> codes;
        string str("0");
        for(int i = 1; i < n; i++) {
            str += "0";
        }
        codes[str] = 0;
        result.push_back(0);
        int num = pow(2, n), val = 0, mul = 1;
        for(int i = 1; i < num; i++) {
            string temp("0");
            for(int j = 0; j < n; j++) {
                temp = str;
                if(str[j] == '0') {
                    temp[j] = '1';
                } else {
                    temp[j] = '0';
                }
                if(!codes.count(temp)) {
                    codes[temp] = i;
                    for(int k = n - 1; k > -1; k--) {
                        if(temp[k] == '1') {
                            val += mul;
                        }
                        mul *= 2;
                    }
                    result.push_back(val);
                    val = 0;
                    mul = 1;
                    str = temp;
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
	Solution s;
	vector<int> res = s.grayCode(3);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}