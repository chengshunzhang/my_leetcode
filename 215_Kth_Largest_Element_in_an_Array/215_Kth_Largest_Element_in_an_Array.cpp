#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i = 0; i < nums.size(); i++) {
            if(pq.size() < k) {
                pq.push(nums[i]);
            } else if(nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

int main() {
	int n[] = {3,2,1,5,6,4};
	vector<int> nums(n, n + 6);
	int k = 2;
	Solution s;
	cout << s.findKthLargest(nums, k) << endl;
	return 0;
}