#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> appear(32, 0);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < 32; j++) {
                if((nums[i] & (1 << j)) != 0) {
                    appear[j]++;
                }
            }
        }
        int result = 0;
        for(int i = 0; i < 32; i++) {
            appear[i] %= 3;
            if(appear[i] != 0) {
                result += (1 << i);
            }
        }
        return result;
    }
};

int main() {
	int n[] = {2,2,3,2};
	vector<int> nums(n,n+4);
	Solution s;
	cout << s.singleNumber(nums) << endl;
	return 0;
}