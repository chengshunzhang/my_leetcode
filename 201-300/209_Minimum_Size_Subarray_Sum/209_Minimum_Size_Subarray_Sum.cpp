#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = nums.size() + 1, sum = 0, start = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum >= s) {
                while(sum - nums[start] >= s) {
                    sum = sum - nums[start];
                    start++;
                }
                int len = i - start + 1;
                if(len == 1) {
                    return 1;
                } else if(len < result) {
                    result = len;
                }
            }
        }
        if(sum < s) {
            return 0;
        } else {
            return result;
        }
    }
};

int main() {
	int s = 7, n[] = {2,3,1,2,4,3};
	vector<int> nums(n, n + 6);
	Solution sol;
	cout << sol.minSubArrayLen(s, nums) << endl;
	return 0;
}