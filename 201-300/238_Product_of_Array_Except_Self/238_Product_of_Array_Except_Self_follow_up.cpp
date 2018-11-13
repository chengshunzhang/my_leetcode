#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        for(int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        int temp = 1;
        for(int i = n - 2; i >= 0; i--) {
            temp = temp * nums[i + 1];
            result[i] = result[i] * temp;
        }
        return result;
    }
};

int main() {
	int n[] = {1,2,3,4};
	vector<int> nums(n,n+4);
	Solution s;
	vector<int> res = s.productExceptSelf(nums);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}