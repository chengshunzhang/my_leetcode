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
        }
    }
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> temp;
        helper(result, nums, temp, 0);
        return result;
    }
};

int main() {
	Solution s;
	int n[] = {1,2,3};
	vector<int> nums(n, n + 3);
	vector<vector<int> > res = s.subsets(nums);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}