#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result, start = 0, end = nums.size() - 1;
        if(nums[start] >= target) {
            return 0;
        }
        if(nums[end] < target) {
            return end + 1;
        }
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if(nums[start] == target) {
            return start;
        }
        if(nums[end] == target) {
            return end;
        }
        return end;
    }
};

int main() {
    int n[] = {1,3,5,6}, target = 5;
    vector<int> nums(n,n+4);
    Solution s;
    cout << s.searchInsert(nums,target) << endl;
    return 0;
}