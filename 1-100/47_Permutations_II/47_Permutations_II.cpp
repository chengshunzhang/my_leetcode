#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void helper(vector<int>& nums, vector<vector<int>>& result, int pos) {
        if(pos == nums.size()) {
            result.push_back(nums);
        }
        for(int i = pos; i < nums.size(); i++) {
            if(i != pos && nums[i] == nums[pos]) {
                continue;
            }
            int j = i - 1;
            while(j >= pos && nums[j] != nums[i]) {
                j--;
            }
            if(j != pos - 1) {
                continue;
            }
            swap(nums[i], nums[pos]);
            helper(nums, result, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        helper(nums, result, 0);
        return result;
    }
};

int main() {
	vector<int> nums = {1, 1, 2};
	Solution s;
	vector<vector<int>> res = s.permuteUnique(nums);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}