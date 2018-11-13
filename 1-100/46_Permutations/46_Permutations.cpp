#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void helper(vector<int>& nums, vector<vector<int> >& result, vector<int>& temp, int pos) {
        if(temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[pos]);
        helper(nums, result, temp, pos + 1);
        temp.pop_back();
        for(int i = pos + 1; i < nums.size(); i++) {
            swap(nums[pos], nums[i]);
            temp.push_back(nums[pos]);
            helper(nums, result, temp, pos + 1);
            swap(nums[pos], nums[i]);
            temp.pop_back();
            
        }
    }
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> temp;
        helper(nums, result, temp, 0);
        return result;
    }
};

int main() {
	int n[] = {1,2,3};
	vector<int> nums(n,n+3);
	Solution s;
	vector<vector<int> > res = s.permute(nums);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}