#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0, pos = -1;
		int n = nums.size();
		if(!n)
			return 0;
		while(i < n) {
			while(i < n - 1 && nums[i] == nums[i + 1]) {
				i++;
			}
			nums[++pos] = nums[i++];
		}
		return pos + 1;
	}
};

int main() {
	int n[] = {0,0,1,1,1,2,2,3,3,4};
	vector<int> nums(n,n+10);
	// int n[] = {1,1,2};
	// vector<int> nums(n,n+3);
	Solution s;
	cout << s.removeDuplicates(nums) << endl;
	return 0;
}