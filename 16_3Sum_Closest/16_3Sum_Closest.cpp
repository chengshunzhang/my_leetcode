#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int diff = 99999999, i = 0;
		bool bigger = true;
		while(i < nums.size()) {
			int num = target - nums[i];
			int left = i + 1, right = nums.size() - 1;
			while(left < right) {
				int temp = nums[left] + nums[right];
				int tempdiff;
				if(temp > num) {
					tempdiff = temp - num;
					right--;
				}
				else if(temp < num) {
					tempdiff = num - temp;
					left++;
				}
				else {
					return target;
				}
				if(tempdiff < diff) {
					diff = tempdiff;
					temp > num ? bigger = true: bigger = false;
				}
			}
			i++;
			while(nums[i] == nums[i - 1])
				i++;
		}
		return bigger == true ? (target + diff) : (target - diff);
	}
};

int main() {
	int n[] = {0,2,1,-3}, target = 1;
	vector<int> nums(n,n+4);
	Solution s;
	cout << s.threeSumClosest(nums,target) << endl;
	return 0;
}