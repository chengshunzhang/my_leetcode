#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> pos;
        for(int i = 0; i < nums.size(); i++) {
            if(pos.empty() || nums[i] >= nums[pos.back()]) {
                pos.push_back(i);
            } else {
                while(!pos.empty() && nums[i] > nums[pos.front()]) {
                    pos.pop_front();
                }
                pos.push_front(i);
            }
            while(pos.back() < i + 1 - k) {
                pos.pop_back();
            }
            if(i >= k - 1) {
                result.push_back(nums[pos.back()]);
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    Solution s;
    vector<int> res = s.maxSlidingWindow(nums, 3);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}