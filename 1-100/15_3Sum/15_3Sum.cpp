#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if(nums.size() < 3) {
            return result;
        }
		sort(nums.begin(), nums.end());
        if(nums[0] > 0 || nums.back() < 0) {
            return result;
        }
		for(int i = 0; i < nums.size() - 2; i++) {
			if(nums[i] + nums[i + 1] + nums[i + 2] > 0) {
                break;
            }
            if(nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] < 0) {
                continue;
            }
			int target = -nums[i], left = i + 1, right = nums.size() - 1;
			while(left < right) {
				if(nums[left] + nums[right] == target) {
					result.push_back({nums[i], nums[left], nums[right]});
					left++;
					while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
					right--;
					while (right > left && nums[right] == nums[right + 1]) {
                       right--; 
                    }
				} else if(nums[left] + nums[right] < target) {
					left++;
				} else
					right--;
			}
            while(i < nums.size() - 2 && nums[i] == nums[i + 1]) {
                i++;
            }
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