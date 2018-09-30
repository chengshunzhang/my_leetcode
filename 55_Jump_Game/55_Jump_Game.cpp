#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), rightMost = 0;
        for(int i = 0; i < n - 1; i++) {
            if(i > rightMost) {
                return false;
            }
            int temp = i + nums[i];
            if(temp > rightMost) {
                rightMost = temp;
            }
        }
        if(rightMost >= n - 1) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
	Solution s;
	int n[] = {2,3,1,1,4};
	vector<int> nums(n, n + 5);
	cout << s.canJump(nums) << endl;
	return 0;
}