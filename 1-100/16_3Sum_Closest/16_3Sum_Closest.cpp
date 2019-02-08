#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int diff = INT_MAX, result = target;
		for(int i = 0; i + 2 < nums.size(); i++) {
			int left = i + 1, right = nums.size() - 1;
			while(left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if(sum > target) {
					right--;
				}
				else if(sum < target) {
					left++;
				}
				else {
					return target;
				}
				if(abs(sum - target) < diff) {
					diff = abs(sum - target);
					result = sum;
				}
			}
		}
		return result;
	}
};

int main() {
	int n[] = {0,2,1,-3}, target = 1;
	vector<int> nums(n,n+4);
	Solution s;
	cout << s.threeSumClosest(nums,target) << endl;
	return 0;
}