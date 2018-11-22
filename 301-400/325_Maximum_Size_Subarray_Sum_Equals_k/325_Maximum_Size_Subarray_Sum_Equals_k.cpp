#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if(nums.empty()) {
            return 0;
        }
        vector<int> sums(nums.size());
        unordered_map<int, int> hash;
        sums[0] = nums[0];
        hash[sums[0]] = 0;
        int len = sums[0] == k ? 1 : 0;
        for(int i = 1; i < sums.size(); i++) {
            sums[i] = sums[i - 1] + nums[i];
            if(sums[i] == k) {
                len = i + 1;
            }
            if(!hash.count(sums[i])) {
                hash[sums[i]] = i;
            }
        }
        for(int j = 1; j < sums.size(); j++) {
            int target = sums[j] - k;
            if(hash.count(target) && j - hash[target] > len) {
                len = j - hash[target];
            }
        }
        return len;
    }
};

int main() {
	int n[] = {1, -1, 5, -2, 3}, k = 3;
	vector<int> nums(n,n+5);
	Solution s;
	cout << s.maxSubArrayLen(nums, k) << endl;
	return 0;
}