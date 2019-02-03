#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            auto it = hash.find(diff);
            if(it != hash.end()) {
                result.push_back(i);
                result.push_back(it -> second);
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};

int main() {
	Solution s;
	int target = 9;
	vector<int> nums = {2, 7, 11, 15};
	vector<int> result = s.twoSum(nums, target);
	cout << result[0] << ',' << result[1] << endl;
	return 0;
}