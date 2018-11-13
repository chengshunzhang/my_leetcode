#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		int i = n - 1, j = n - 1;
		while(i > 0 && nums[i] <= nums[i - 1])
			i--;
		int temp, p = i + 1;
		while(p < n && nums[p] > nums[i - 1]) {
			p++;
		}
		if(i) {
			temp = nums[p - 1]; nums[p - 1] = nums[i - 1]; nums[i - 1] = temp;
		}
		while(i < j) {
			temp = nums[i]; nums[i] = nums[j]; nums[j] = temp;
			i++;
			j--;
		}
	}
};

int main() {
	int n[] = {5,1,1}; //2,3,1 -> 3,1,2
	vector<int> nums(n,n+3);
	Solution s;
	s.nextPermutation(nums);
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << ' ';
	cout << endl;
	return 0;
}