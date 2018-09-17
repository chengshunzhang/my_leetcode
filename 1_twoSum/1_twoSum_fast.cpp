#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			m[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); i++) {
			unordered_map<int, int>::iterator itr = m.find(target - nums[i]);
			if (itr != m.end() && itr -> second != i) {
				result.push_back(i); result.push_back(itr -> second);
				break;
			}
		}
		return result;
	}
};

int main(){
	Solution s;
	int n[] = {2,7,11,15}; int target = 9;
	vector<int> nums(n,n+4);
	vector<int> result = s.twoSum(nums,target);
	cout << result[0] << endl << result[1] << endl;
	return 0;
}