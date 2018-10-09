#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void helper(vector<vector<int> >& result, vector<int>& temp, vector<int>& nums, int k, int n, int pos, int& sum, int& num) {
        if(num == k && sum == n) {
            result.push_back(temp);
            return;
        }
        for(int i = pos; i < 10; i++) {
            if(sum < n && num < k) {
                temp.push_back(nums[i]);
                sum = sum + nums[i];
                num++;
                helper(result, temp, nums, k, n, i + 1, sum, num);
                temp.pop_back();
                sum = sum - nums[i];
                num--;
            } else {
                break;
            } 
        }
    }
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> temp, nums(9);
        for(int i = 1; i < 10; i++) {
            nums[i - 1] = i;
        }
        int sum = 0, num = 0;
        helper(result, temp, nums, k, n, 0, sum, num);
        return result;
    }
};

int main() {
	int n = 7, k = 3;
	Solution s;
	vector<vector<int> > res = s.combinationSum3(k, n);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ' ';	
		}
		cout << endl;
	}
	return 0;
}