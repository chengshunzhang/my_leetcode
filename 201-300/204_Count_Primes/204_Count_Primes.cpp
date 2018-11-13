#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> nums(n, false);
        int result = 0;
        for(int i = 2; i < n; i++) {
            if(nums[i] == false) {
                result++;
                nums[i] = true;
                for(int j = 2; i * j < n; j++) {
                    nums[i * j] = true;
                }
            }
        }
        return result;
    }
};

int main() {
	Solution s;
	cout << s.countPrimes(10) << endl;
	return 0;
}