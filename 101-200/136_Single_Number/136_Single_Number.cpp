#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            single ^= nums[i];
        }
        return single;
    }
};

int main() {
	int n[] = {2,2,1};
	vector<int> nums(n,n+3);
	Solution s;
	cout << s.singleNumber(nums) << endl;
	return 0;
}