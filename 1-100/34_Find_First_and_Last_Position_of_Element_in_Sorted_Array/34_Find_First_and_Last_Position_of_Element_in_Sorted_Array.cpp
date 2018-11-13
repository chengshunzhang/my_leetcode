#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int start = 0, end = nums.size() - 1, start_pos = -1, end_pos = -1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) {
                start_pos = end_pos = mid;
                while(start_pos > 0 && nums[start_pos] == nums[start_pos - 1]) {
                    start_pos--;
                }
                while(end_pos < nums.size() - 1 && nums[end_pos] == nums[end_pos + 1]) {
                    end_pos++;
                }
                break;
            } else if(nums[mid] > target){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        result.push_back(start_pos);
        result.push_back(end_pos);
        return result;
    }
};

int main() {
	int n[] = {5,7,7,8,8,10}, target = 8;
	vector<int> nums(n,n+6);
	Solution s;
	vector<int> res = s.searchRange(nums, target);
	cout << '[' << res[0] << ',' << res[1] << ']' << endl;
	return 0;
}