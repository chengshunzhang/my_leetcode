#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> forward(n + 1, 1), backward(n + 1, 1);
        for(int i = 0; i < n; i++) {
            forward[i + 1] = forward[i] * nums[i];
            backward[n - i - 1] = backward[n - i] * nums[n - i - 1];
        }
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            result[i] = forward[i] * backward[i + 1];
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