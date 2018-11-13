#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        n--;
        while(n >= 0) {
            char c = n % 26 + 'A';
            result.push_back(c);
            n = n / 26 - 1;
        }
        for(int i = 0, j = result.size() - 1; i < j; i++, j--) {
            char temp = result[i];
            result[i] = result[j];
            result[j] = temp;
        }
        return result;
    }
};

int main() {
	Solution s;
	int n = 27;
	cout << s.convertToTitle(n) << endl;
	return 0;
}