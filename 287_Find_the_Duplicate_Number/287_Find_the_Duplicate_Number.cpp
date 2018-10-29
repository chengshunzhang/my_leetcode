#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int pos = nums[i] - 1;
            if(i != pos) {
                if(nums[pos] == nums[i]) {
                    return nums[i];
                } else {
                    swap(nums[i], nums[pos]);
                    i--;
                }
            }
        }
        return -1;
    }
};

int main() {
	int n[] = {1,3,4,2,2};
	vector<int> nums(n,n+5);
	Solution s;
	cout << s.findDuplicate(nums) << endl;
	return 0;
}