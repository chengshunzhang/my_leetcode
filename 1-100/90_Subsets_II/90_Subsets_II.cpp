#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void helper(vector<vector<int> >& result, vector<int>& nums, vector<int>& temp, int pos) {
        result.push_back(temp);
        for(int i = pos; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            helper(result, nums, temp, i + 1);
            temp.pop_back();
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            }
        }
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> temp;
        helper(result, nums, temp, 0);
        return result;
    }
};

int main() {
	Solution s;
	vector<vector<int> > result;
	int n[] = {1,2,2};
	vector<int> nums(n, n + 3);
	result = s.subsetsWithDup(nums);
	for(int i = 0; i < result.size(); i++) {
		for(int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}