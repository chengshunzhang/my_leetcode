#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, start = 0, netGain = 0;
        for(int i = 0; i < gas.size(); i++) {
            int curGain = gas[i] - cost[i];
            netGain += curGain;
            total += curGain;
            if(total < 0) {
                start = i + 1;
                total = 0;
            }
        }
        return netGain < 0 ? -1 : start;
    }
};

int main() {
	Solution s;
	int g[] = {1,2,3,4,5}, c[] = {3,4,5,1,2};
	vector<int> gas(g,g+5), cost(c,c+5);
	cout << s.canCompleteCircuit(gas, cost) << endl;
	return 0;
}