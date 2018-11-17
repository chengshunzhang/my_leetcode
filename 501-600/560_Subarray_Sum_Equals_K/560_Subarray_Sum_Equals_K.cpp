#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0, n = nums.size();
        vector<int> sums(n);
        unordered_map<int, vector<int> > hash;
        sums[0] = nums[0];
        hash[sums[0]].push_back(0);
        for(int i = 1; i < n; i++) {
            sums[i] = sums[i - 1] + nums[i];
            hash[sums[i]].push_back(i);
        }
        for(int i = 0; i < n; i++) {
            int diff = sums[i] - k;
            if(diff == 0) {
                result++;
            }
            if(hash.count(diff)) {
                int j = 0;
                while(j < hash[diff].size() && hash[diff][j] < i) {
                    j++;
                    result++;
                }
            }
        }
        return result;
    }
};

int main() {
	int n[] = {1,1,1}, k = 2;
	vector<int> nums(n,n+3);
	Solution s;
	cout << s.subarraySum(nums, k) << endl;
	return 0;
}