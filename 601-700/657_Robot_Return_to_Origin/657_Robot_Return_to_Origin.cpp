#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontal = 0, vertical = 0;
        for(int i = 0; i < moves.size(); i++) {
            if(moves[i] == 'L') {
                horizontal--;
            } else if(moves[i] == 'R') {
                horizontal++;
            } else if(moves[i] == 'U') {
                vertical++;
            } else {
                vertical--;
            }
        }
        return horizontal == 0 && vertical == 0;
    }
};

int main() {
	string moves("UD");
	Solution s;
	cout << s.judgeCircle(moves) << endl;
	return 0;
}