#include <set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int, greater<int> > ms;
        int n = nums.size(), start = 0, end = 0;
        if(n == 0) {
            return vector<int> ();
        }
        vector<int> result(n - k + 1);
        while(end < k) {
            ms.insert(nums[end]);
            end++;
        }
        while(end < n) {
            result[start] = *ms.begin();
            ms.erase(ms.find(nums[start++]));
            ms.insert(nums[end++]);
        }
        result[start] = *ms.begin();
        return result;
    }
};

int main() {
	int n[] = {1,3,-1,-3,5,3,6,7};
	vector<int> nums(n,n+8);
	Solution s;
	vector<int> res = s.maxSlidingWindow(nums, 3);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}