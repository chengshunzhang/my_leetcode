#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
        int n = nums.size();
        if(n < 4) {
            return result;
        } 
		sort(nums.begin(), nums.end());
        for(int i = 0; i + 3 < n; i++) {
            for(int j = i + 1; j + 2 < n; j++) {
                int targetSum = target - nums[i] - nums[j], left = j + 1, right = n - 1;
                while(left < right) {
                    int sum = nums[left] + nums[right];
                    if(sum == targetSum) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                        while(left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    } else if(sum < targetSum) {
                        left++;
                    } else {
                        right--;
                    }
                }
                while(j + 2 < n && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            while(i + 3 < n && nums[i] == nums[i + 1]) {
                i++;
            }
        }
		return result;
	}
};

int main(){
	vector<int> nums = {1, 0, -1, 0, -2, 2}, target = 0;
	Solution s;
	vector< vector<int> > res = s.fourSum(nums, target);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < 4; j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}