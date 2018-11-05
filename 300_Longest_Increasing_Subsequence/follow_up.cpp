#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        vector<int> tails(1, nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > tails.back()) {
                tails.push_back(nums[i]);
            } if(nums[i] <= tails[0]) {
                tails[0] = nums[i];
            } else {
                *lower_bound(tails.begin(), tails.end(), nums[i]) = nums[i];
            }
        }
        return tails.size();
    }
};

int main() {
	int n[] = {10,9,2,5,3,7,101,18};
	vector<int> nums(n,n+8);
	Solution s;
	cout << s.lengthOfLIS(nums) << endl;
	return 0;
}