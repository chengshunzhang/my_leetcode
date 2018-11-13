#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector< vector<int> > fourSum(vector<int>& nums, int target) {
		vector< vector<int> > result;
		if(nums.size() < 4)
			return result;
		sort(nums.begin(), nums.end());
		int i = 0;
		while(i < nums.size() - 3) {
			int j = i + 1, target3 = target - nums[i];
			while(j < nums.size() - 2) {
				int num = target3 - nums[j];
				int left = j + 1, right = nums.size() - 1;
				while (left < right) {
					if(nums[left] + nums[right] == num) {
						vector<int> temp;
						temp.push_back(nums[i]); temp.push_back(nums[j]); temp.push_back(nums[left]); temp.push_back(nums[right]);
						result.push_back(temp);
						left++;
						while(nums[left] == nums[left - 1])
							left++;
						right--;
						while(nums[right] == nums[right + 1])
							right--;
					}
					else if(nums[left] + nums[right] > num)
						right--;
					else
						left++;
				}
				j++;
				while(nums[j] == nums[j - 1])
					j++;
			}
			i++;
			while(nums[i] == nums[i - 1])
				i++;
		}
		return result;
	}
};

int main(){
	int n[] = {1, 0, -1, 0, -2, 2}, target = 0;
	vector<int> nums(n,n+6);
	Solution s;
	vector< vector<int> > res = s.fourSum(nums, target);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < 4; j++)
			cout << res[i][j] << ' ';
		cout << endl;
	}
	return 0;
}