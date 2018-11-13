#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int findMax(int left, int right, vector<int>& nums) {
        if(left > right) {
            return (1 << 31);
        }
        if(left == right) {
            return nums[left];
        }
        int negNum = 0;
        vector<int> negPos;
        for(int i = left; i <= right; i++) {
            if(nums[i] < 0) {
                negNum++;
                negPos.push_back(i);
            }
        }
        if(negNum % 2 == 0) {
            int result = 1;
            for(int i = left; i <= right; i++) {
                result *= nums[i];
            }
            return result;
        } else {
            int maxv = 1, temp = 1;
            for(int i = left; i < negPos[negNum - 1]; i++) {
                temp *= nums[i];
            }
            for(int i = negPos[0] + 1; i <= right; i++) {
                maxv *= nums[i];
            }
            return maxv > temp ? maxv : temp;
        }
    }
public:
    int maxProduct(vector<int>& nums) {
        int maxv = 1 << 31, n = nums.size();
        vector<int> zeropos(1, -1);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                zeropos.push_back(i);
                maxv = 0;
            }
        }
        zeropos.push_back(n);
        int m = zeropos.size();
        for(int i = 0; i + 1 < m; i++) {
            int temp = findMax(zeropos[i] + 1, zeropos[i + 1] - 1, nums);
            if(temp > maxv) {
                maxv = temp;
            }
        }
        return maxv;
    }
};

int main() {
	int n[] = {2,3,-2,4};
	Solution sol;
	vector<int> nums(n,n+4);
	cout << sol.maxProduct(nums) << endl;
	return 0;
}