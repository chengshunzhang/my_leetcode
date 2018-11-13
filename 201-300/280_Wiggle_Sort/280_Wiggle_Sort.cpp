#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool even = true;
        for(int i = 0; i + 1 < nums.size(); i++) {
            if(even && nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
            if(!even && nums[i] < nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
            even ^= 1;
        }
    }
};

int main() {
	int n[] = {3,5,2,1,6,4};
	vector<int> nums(n,n+6);
	Solution s;
	s.wiggleSort(nums);
	for(int i = 0; i < nums.size(); i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
	return 0;
}