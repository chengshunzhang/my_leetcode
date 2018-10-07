#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0 || n == 1) {
            return;
        }
        int div = (n - k) > 0 ? n - k : n - k % n;
        if(div == n) {
            return;
        }
        for(int i = 0, j = div - 1; i < j; i++, j--) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        for(int i = div, j = n - 1; i < j; i++, j--) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        for(int i = 0, j = n - 1; i < j; i++, j--) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
};

int main() {
	Solution s;
	int n[] = {1,2,3,44,6,7};
	vector<int> nums(n,n+6);
	s.rotate(nums, 3);
	for(int i = 0; i < nums.size(); i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
	return 0;
}