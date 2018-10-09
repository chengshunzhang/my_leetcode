#include <set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || nums.empty()) {
            return false;
        }
        int n = nums.size();
        multiset<int> ms;
        ms.insert(nums[0]);
        for(int i = 1; i < n && i <= k; i++) {
            ms.insert(nums[i]);
            multiset<int>::iterator it = ms.find(nums[i]);
            if(it != ms.begin()) {
                multiset<int>::iterator it_pre = --it;
                it++;
                if(nums[i] - *it_pre >= 0 && nums[i] - *it_pre <= t) {
                    return true;
                }
            }
            if(++it != ms.end()) {
                multiset<int>::iterator it_aft = it;
                if(*it_aft - nums[i] >= 0 && *it_aft - nums[i] <= t) {
                    return true;
                }
            }
        }
        for(int i = k + 1; i < n; i++) {
            ms.erase(ms.find(nums[i - k - 1]));
            ms.insert(nums[i]);
            multiset<int>::iterator it = ms.find(nums[i]);
            if(it != ms.begin()) {
                multiset<int>::iterator it_pre = --it;
                it++;
                if(nums[i] - *it_pre >= 0 && nums[i] - *it_pre <= t) {
                    return true;
                }
            }
            if(++it != ms.end()) {
                multiset<int>::iterator it_aft = it;
                if(*it_aft - nums[i] >= 0 && *it_aft - nums[i] <= t) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
	int n[] = {-1,2147483647}, k = 1, t = 2147483647;
	vector<int> nums(n,n+2);
	Solution s;
	cout << s.containsNearbyAlmostDuplicate(nums, k, t) << endl;
	return 0;
}