#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int binarySearch(int num, vector<pair<string, int> >& rtoi) {
        int left = 0, right = 12;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(rtoi[mid].second == num) {
                return mid;
            } else if(rtoi[mid].second > num) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if(rtoi[right].second <= num) {
            return right;
        }
        return left;
    }
public:
    string intToRoman(int num) {
        vector<pair<string, int> > rtoi(13);
        rtoi[0] = make_pair("I", 1);
        rtoi[1] = make_pair("IV", 4);
        rtoi[2] = make_pair("V", 5);
        rtoi[3] = make_pair("IX", 9);
        rtoi[4] = make_pair("X", 10);
        rtoi[5] = make_pair("XL", 40);
        rtoi[6] = make_pair("L", 50);
        rtoi[7] = make_pair("XC", 90);
        rtoi[8] = make_pair("C", 100);
        rtoi[9] = make_pair("CD", 400);
        rtoi[10] = make_pair("D", 500);
        rtoi[11] = make_pair("CM", 900);
        rtoi[12] = make_pair("M", 1000);
        string result = "";
        while(num > 0) {
            int idx = binarySearch(num, rtoi);
            num -= rtoi[idx].second;
            result += rtoi[idx].first;
        }
        return result;
    }
};

int main() {
	Solution s;
	cout << s.intToRoman(58) << endl;
	return 0;
}