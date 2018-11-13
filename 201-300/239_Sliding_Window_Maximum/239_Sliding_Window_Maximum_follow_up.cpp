#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) {
            return vector<int> ();
        }
        vector<int> result(n - k + 1);
        deque<int> dq;
        dq.push_back(0);
        for(int i = 1; i < k; i++) {
            while(!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i = k; i < n; i++) {
            result[i - k] = nums[dq.front()];
            if(dq.front() == i - k) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        result[n - k] = nums[dq.front()];
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