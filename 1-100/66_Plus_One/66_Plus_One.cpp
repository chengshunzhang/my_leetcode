#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits);
        int n = digits.size() - 1;
        if(result[n] < 9) {
            result[n] += 1;
        } else {
            result[n] = 0;
            int i = n - 1;
            while(i >= 0) {
                if(result[i] < 9) {
                    result[i] += 1;
                    break;
                } else {
                    result[i] = 0;
                }
                i--;
            }
            if(i == -1) {
                result.push_back(0);
                result[0] = 1;
            }
        }
        return result;
    }
};

int main() {
	Solution s;
	int d[] = {1,2,4};
	vector<int> digits(d, d + 3);
	vector<int> res = s.plusOne(digits);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}