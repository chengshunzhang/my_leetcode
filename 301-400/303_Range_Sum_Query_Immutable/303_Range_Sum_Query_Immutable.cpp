#include <vector>
#include <iostream>
using namespace std;

class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        sums.push_back(0);
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sums.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};

int main() {
	vector<int> nums = {-2, 0, 3, -5, 2, -1};
	NumArray numArray(nums);
	cout << numArray.sumRange(0, 2) << endl;
	cout << numArray.sumRange(2, 5) << endl;
	cout << numArray.sumRange(0, 5) << endl;
	return 0;
}