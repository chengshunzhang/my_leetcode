#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }
        for(int i = index; i < n; i++) {
            nums[i] = 0;
        }
    }
};

int main() {
	Solution s;
	int n[] = {0,1,0,3,12};
	vector<int> nums(n,n+5);
	s.moveZeroes(nums);
	for(int i = 0; i < nums.size(); i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
	return 0;
}