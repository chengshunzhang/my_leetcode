#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void helper(vector<int>& coins, int pos, int curAmount, int& minimum, int& curNum) {
        int num = curAmount / coins[pos];
        curNum += num;
        if(curNum > minimum) {
            curNum -= num;
            return;
        }
        int amt = curAmount - num * coins[pos];
        if(amt == 0) {
            minimum = curNum;
            curNum -= num;
            return;
        }
        if(pos == 0) {
            curNum -= num;
            return;
        }
        curNum -= num;
        for(int i = num; i >= 0; i--) {
            amt = curAmount - i * coins[pos];
            curNum += i;
            helper(coins, pos - 1, amt, minimum, curNum);
            curNum -= i;
        }
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int minimum = ((uint)1 << 31) - 1, curNum = 0;
        helper(coins, coins.size() - 1, amount, minimum, curNum);
        return minimum == ((uint)1 << 31) - 1 ? -1 : minimum;
    }
};

int main() {
	int n[] = {186,419,83,408}, amount = 6249;
	vector<int> coins(n,n+4);
	Solution s;
	cout << s.coinChange(coins, amount) << endl;
	return 0;
}