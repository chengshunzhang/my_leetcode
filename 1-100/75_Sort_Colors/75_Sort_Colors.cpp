#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int last = nums.size() - 1, first = 0;
        for(int i = 0; i <= last; i++) {
            if(nums[i] == 0) {
                if(i != first) {
                    nums[i] = nums[first];
                    nums[first] = 0;
                    i--;
                }
                first++;
            }
            if(nums[i] == 2) {
                nums[i] = nums[last];
                nums[last] = 2;
                last--;
                i--;
            }
        }
    }
};

int main() {
	int n[] = {2,0,2,1,1,0};
	vector<int> nums(n, n + 6);
	Solution s;
	s.sortColors(nums);
	for(int i = 0; i < nums.size(); i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
	return 0;
}