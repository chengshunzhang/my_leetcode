#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = 1 << 31, sumNow = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(sumNow >= 0) {
                sumNow += nums[i];
            } else {
                sumNow = nums[i];
            }
            if(sumNow > result) {
                result = sumNow;
            }
        }
        return result;
    }
};

int main() {
	Solution s;
	int n[] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> nums(n, n + 9);
	cout << s.maxSubArray(nums) << endl;
	return 0;
}