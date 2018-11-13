#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int binarySearch(int target, int left, int right, vector<int>& nums) {
		while(left <= right) {
			int mid = (left + right) / 2;
			if(target == nums[mid])
				return mid;
			else if(target < nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		return -1;
	}

	int search(vector<int>& nums, int target) {
		int i = 0, n = nums.size();
		if(!n)
			return -1;
		while(i < n - 1 && nums[i] < nums[i + 1])
			i++;
		if(target > nums[i])
			return -1;
		else if(target == nums[i])
			return i;
		else if(target == nums[0])
			return 0;
		else if(target == nums[n - 1])
			return n - 1;
		else if(target > nums[0] && target < nums[i])
			return binarySearch(target, 0, i, nums);
		else
			return binarySearch(target, i + 1, n - 1, nums);
	}
};

int main() {
	int n[] = {0,1,2,3,4,5,6}, target = 3;
	vector<int> nums(n,n+7);
	Solution s;
	cout << s.search(nums, target) << endl;
	return 0;
}