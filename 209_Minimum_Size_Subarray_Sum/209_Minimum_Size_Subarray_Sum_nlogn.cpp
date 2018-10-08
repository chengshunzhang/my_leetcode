#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int binarySearch(vector<int>& sums, int target, int start, int right) {
        if(sums[right] < target) {
            return sums.size();
        }
        int left = start;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(sums[mid] == target) {
                return mid - start;
            } else if(sums[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if(sums[left] >= target) {
            return left - start;
        } else {
            return right - start;
        }
    }
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), result = n + 1;
        vector<int> sums(n + 1);
        sums[0] = 0;
        for(int i = 1; i < n + 1; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        if(sums[n] < s) {
            return 0;
        }
        for(int i = 0; i < n; i++) {
            int temp = binarySearch(sums, s + sums[i], i, n);
            if(temp == 1) {
                return 1;
            }
            if(temp < result) {
                result = temp;
            }
        }
        return result;
    }
};

int main() {
	int s = 7, n[] = {2,3,1,2,4,3};
	vector<int> nums(n, n + 6);
	Solution sol;
	cout << sol.minSubArrayLen(s, nums) << endl;
	return 0;
}