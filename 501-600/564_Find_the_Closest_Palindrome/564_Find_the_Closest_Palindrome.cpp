#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        if(n.size() == 1) {
            return to_string(n[0] - '1');
        }
        if(n.size() == 2) {
            if(n == "10" || n == "11") {
                return "9";
            }
            if(stoi(n) <= 16 || n == "22") {
                return "11";
            }
            if(stoi(n) <= 27) {
                return "22";
            }
        }
        string left = n.substr(0, (n.size() + 1) / 2), result;
        string leftSubOne = to_string(stoi(left) - 1), leftAddOne = to_string(stoi(left) + 1);
        string right(left), rightSubOne(leftSubOne), rightAddOne(leftAddOne);
        reverse(right.begin(), right.end());
        reverse(rightSubOne.begin(), rightSubOne.end());
        reverse(rightAddOne.begin(), rightAddOne.end());
        string candidate1, candidate2;
        if(leftSubOne.size() < left.size()) {
            candidate1 = string(n.size() - 1, '9');
            candidate2 = n.size() % 2 == 0 ? leftAddOne + rightAddOne : leftAddOne + rightAddOne.substr(1);
        } else if(leftAddOne.size() > left.size()) {
            candidate1 = n.size() % 2 == 0 ? leftSubOne + rightSubOne : leftSubOne + rightSubOne.substr(1);
            candidate2 = "1" + string(n.size() - 1, '0') + "1";
        } else {
            candidate1 = n.size() % 2 == 0 ? leftSubOne + rightSubOne : leftSubOne + rightSubOne.substr(1);
            candidate2 = n.size() % 2 == 0 ? leftAddOne + rightAddOne : leftAddOne + rightAddOne.substr(1);
        }
        long diff1 = stol(n) - stol(candidate1), diff2 = stol(candidate2) - stol(n), diff;
        if(diff1 <= diff2) {
            result = candidate1;
            diff = diff1;
        } else {
            result = candidate2;
            diff = diff2;
        }
        if(right != n.substr(n.size() / 2)) {
            string candidate3 = n.size() % 2 == 0 ? left + right : left + right.substr(1);
            long diff3 = abs(stol(n) - stol(candidate3));
            if(diff3 < diff || (diff3 == diff && result == candidate2)) {
                result = candidate3;
            }
        }
        return result;
    }
};

int main() {
	Solution s;
	string n("123");
	cout << s.nearestPalindromic(n) << endl;
	return 0;
}