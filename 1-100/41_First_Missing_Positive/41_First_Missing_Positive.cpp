#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0 && nums[i] - 1 < n && nums[nums[i] - 1] != nums[i]) {
                int p = nums[i] - 1;
                int temp = nums[i];
                nums[i] = nums[p];
                nums[p] = temp;
                i--;
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

int main() {
    Solution s;
    int n[] = {7,8,9,11,12,1};
    vector<int> nums(n, n + 6);
    cout << s.firstMissingPositive(nums) << endl;
    return 0;
}