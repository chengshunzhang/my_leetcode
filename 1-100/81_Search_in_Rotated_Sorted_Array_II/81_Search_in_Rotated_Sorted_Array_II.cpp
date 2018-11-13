#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) {
            return false;
        }
        for(int i = 0; i + 1 < nums.size(); i++) {
            if(target == nums[i]) {
                return true;
            }
            if(nums[i + 1] < nums[i]) {
                return *lower_bound(nums.begin() + i + 1, nums.end(), target) == target;
            }
        }
        return nums[nums.size() - 1] == target;
    }
};

int main() {
	int n[] = {2,5,6,0,0,1,2}, target = 0;
	vector<int> nums(n,n+7);
	Solution s;
	cout << s.search(nums, target) << endl;
	return 0;
}