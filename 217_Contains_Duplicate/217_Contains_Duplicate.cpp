#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> m;
        for(int i = 0; i < n; i++) {
            if(!m.count(nums[i])) {
                m[nums[i]] = true;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
	int n[] = {1,2,3,1};
	vector<int> nums(n,n+4);
	Solution s;
	cout << s.containsDuplicate(nums) << endl;
	return 0;
}