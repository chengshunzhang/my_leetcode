#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
private:
    bool helper(vector<double> nums) {
        if(nums.size() == 1) {
            return fabs(nums[0] - 24) < 1e-6;
        }
        for(int i = 0; i + 1 < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                double first = (double)nums[i], second = (double)nums[j];
                nums.erase(nums.begin() + j);
                nums.erase(nums.begin() + i);
                double n[] = {(double)first + second, (double)first * second, (double)first - second, (double)second - first};
                vector<double> newNums(n, n  + 4);
                if(fabs(second) > 1e-6) {
                    newNums.push_back((double)first / second);
                }
                if(fabs(first) > 1e-6) {
                    newNums.push_back((double)second / first);
                }
                for(int k = 0; k < newNums.size(); k++) {
                    nums.push_back(newNums[k]);
                    if(helper(nums)) {
                        return true;
                    }
                    nums.pop_back();
                }
                nums.insert(nums.begin() + i, first);
                nums.insert(nums.begin() + j, second);
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> ns(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            ns[i] = (double)nums[i];
        }
        return helper(ns);
    }
};

int main() {
	int n[] = {4,1,8,7};
	vector<int> nums(n, n+4);
	Solution s;
	cout << s.judgePoint24(nums) << endl;
	return 0;
}