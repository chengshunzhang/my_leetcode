#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) {
                five++;
            } else if(bills[i] == 10) {
                if(!five) {
                    return false;
                }
                five--;
                ten++;
            } else {
                if(ten) {
                    ten--;
                    if(!five) {
                        return false;
                    }
                    five--;
                } else {
                    if(five < 3) {
                        return false;
                    }
                    five -= 3;
                }
            }
        }
        return true;
    }
};

int main() {
	int n[] = {5,5,5,10,20};
	vector<int> nums(n,n+5);
	Solution s;
	cout << s.lemonadeChange(nums) << endl;
	return 0;
}