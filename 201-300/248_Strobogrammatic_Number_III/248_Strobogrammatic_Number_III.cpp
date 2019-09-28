#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void calculateLenN(int& result, string& low, string& high, string& temp, int pos) {
        int n = low.size();
        if((n % 2 == 0 && pos == n / 2) || (n % 2 == 1 && pos == n / 2 + 1)) {
            if(temp >= low && temp <= high) {
                result++;
            }
            return;
        }
        int j = n - pos - 1;
        temp[pos] = temp[j] = '1';
        calculateLenN(result, low, high, temp, pos + 1);
        temp[pos] = temp[j] = '8';
        calculateLenN(result, low, high, temp, pos + 1);
        if(pos != j) {
            temp[pos] = '6';
            temp[j] = '9';
            calculateLenN(result, low, high, temp, pos + 1);
            temp[pos] = '9';
            temp[j] = '6';
            calculateLenN(result, low, high, temp, pos + 1);
        }
        if(pos != 0 || n == 1) {
            temp[pos] = temp[j] = '0';
            calculateLenN(result, low, high, temp, pos + 1);
        }
    }
public:
    int strobogrammaticInRange(string low, string high) {
        int lowLen = low.size(), highLen = high.size();
        if(lowLen > highLen || (lowLen == highLen && low > high)) {
            return 0;
        }
        int result = 0;
        for(int i = lowLen; i <= highLen; i++) {
            string temp(i, '0');
            if(i == lowLen && i == highLen) {
                calculateLenN(result, low, high, temp, 0);
            } else if(i == lowLen) {
                string tempH(lowLen, '9');
                calculateLenN(result, low, tempH, temp, 0);
            } else if(i == highLen) {
                string tempL(highLen, '0');
                calculateLenN(result, tempL, high, temp, 0);
            } else {
                string tempL(i, '0'), tempH(i, '9');
                calculateLenN(result, tempL, tempH, temp, 0);
            }
        }
        return result;
    }
};

int main() {
	string low = "0", high = "2147483647";
	Solution sol;
	cout << sol.strobogrammaticInRange(low, high) << endl;
	return 0;
}