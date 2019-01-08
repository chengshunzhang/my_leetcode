#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int min = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < min) {
                min = nums[i];
            }
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i] - min;
        }
        return sum;
    }
};

int main() {
	int n[] = {1, 2, 3};
	vector<int> nums(n, n + 3);
	Solution s;
	cout << s.minMoves(nums) << endl;
	return 0;
}