#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) {
            return false;
        }
        if(k == 0) {
            for(int i = 0; i + 1 < nums.size(); i++) {
                if(nums[i] == 0 && nums[i + 1] == 0) {
                    return true;
                }
            }
            return false;
        } else {
            int sum = nums[0];
            unordered_map<int, int> hash;
            hash[sum % k] = 0;
            for(int i = 1; i < nums.size(); i++) {
                sum += nums[i];
                int remainder = sum % k;
                if(remainder == 0) {
                    return true;
                }
                if(hash.count(remainder) && i - hash[remainder] > 1) {
                    return true;
                } else if(!hash.count(remainder)) {
                    hash[remainder] = i;
                }
            }
            return false;
        }
    }
};

int main() {
	int n[] = {23, 2, 4, 6, 7}, k = 6;
	vector<int> nums(n,n+5);
	Solution s;
	cout << s.checkSubarraySum(nums, k) << endl;
	return 0;
}