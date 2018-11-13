#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
	vector< vector<int> > threeSum(vector<int>& nums) {
		vector< vector<int> > result;
		if (nums.size() < 3)
			return result;
		sort(nums.begin(), nums.end());
		int i = 0;
		while(i < nums.size() - 2) {
			int target = -nums[i], left = i + 1, right = nums.size() - 1;
			while (left < right) {
				if (nums[left] + nums[right] == target) {
					vector<int> temp;
					temp.push_back(nums[i]); temp.push_back(nums[left]); temp.push_back(nums[right]);
					result.push_back(temp);
					left++;
					while (nums[left] == nums[left - 1])
						left++;
					right--;
					while (nums[right] == nums[right + 1])
						right--;
				}
				else if (nums[left] + nums[right] < target) {
					left++;
				}
				else
					right--;
			}
			i++;
			while(nums[i] == nums[i - 1])
				i++;
		}
		return result;
	}
};

int main(){
	int n[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
	vector<int> nums(n, n+16);
	Solution s;
	vector< vector<int> > res = s.threeSum(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < 3; j++)
			cout << res[i][j] << ' ';
		cout << endl;
	}
	
	return 0;
}