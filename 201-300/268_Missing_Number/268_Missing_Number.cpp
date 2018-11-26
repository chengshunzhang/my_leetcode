#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), result = n;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == n) {
                result = i;
            } else if(nums[i] != i){
                swap(nums[i], nums[nums[i]]);
                i--;
            }
        }
        return result;
    }
};

int main() {
	int n[] = {3,0,1};
	vector<int> nums(n,n+3);
	Solution s;
	cout << s.missingNumber(nums) << endl;
	return 0;
}