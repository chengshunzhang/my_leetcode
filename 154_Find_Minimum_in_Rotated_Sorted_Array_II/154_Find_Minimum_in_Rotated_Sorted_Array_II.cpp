#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                return nums[i + 1];
            }
        }
        return nums[0];
    }
};

int main() {
	int n[] = {1,3,3};
	vector<int> nums(n,n+3);
	Solution s;
	cout << s.findMin(nums) << endl;
	return 0;
}