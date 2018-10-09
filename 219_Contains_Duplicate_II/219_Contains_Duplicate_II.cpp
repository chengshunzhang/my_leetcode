#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            if(!m.count(nums[i]) || i - m[nums[i]] > k) {
                m[nums[i]] = i;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
	int n[] = {1,2,3,1}, k = 3;
	vector<int> nums(n,n+4);
	Solution s;
	cout << s.containsNearbyDuplicate(nums, k) << endl;
	return 0;
}