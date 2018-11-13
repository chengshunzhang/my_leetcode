#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size()) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        vector<int> A(n + 1);
        A[0] = 0;
        A[1] = nums[0];
        for(int i = 2; i < n + 1; i++) {
            int temp = nums[i - 1] + A[i - 2];
            A[i] = A[i - 1] > temp ? A[i - 1] : temp;
        }
        return A[n];
    }
};

int main() {
	int n[] = {1,2,3,1};
	vector<int> nums(n,n+4);
	Solution s;
	cout << s.rob(nums) << endl;
	return 0;
}