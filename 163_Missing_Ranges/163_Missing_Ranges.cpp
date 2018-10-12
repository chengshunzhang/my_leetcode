#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int left, n = nums.size();
        long diff;
        vector<string> result;
        if(n == 0) {
            if(upper == lower) {
                result.push_back(to_string(upper));
            } else {
                result.push_back(to_string(lower) + "->" + to_string(upper));
            }
            return result;
        }
        string temp;
        diff = (long)nums[0] - lower;
        if(diff > 0) {
            if(diff > 1) {
                temp.append(to_string(lower) + "->" + to_string(nums[0] - 1));
            } else {
                temp.append(to_string(lower));
            }
            result.push_back(temp);
        }
        temp = "";
        left = nums[0];
        for(int i = 1; i < n; i++) {
            diff = (long)nums[i] - left;
            if(diff > 1) {
                if(diff > 2) {
                    temp.append(to_string(left + 1) + "->" + to_string(nums[i] - 1));
                } else {
                    temp.append(to_string(left + 1));
                }
                result.push_back(temp);
                temp = "";
            }
            left = nums[i];
        }
        diff = (long)upper - nums[n - 1];
        if(diff > 0) {
            if(diff > 1) {
                temp.append(to_string(left + 1) + "->" + to_string(upper));
            } else {
                temp.append(to_string(upper));
            }
            result.push_back(temp);
        }
        return result;
    }
};

int main() {
	Solution s;
	int n[] = {-2147483648, 2147483647};
	vector<int> nums(n,n+2);
	int lower = -2147483648, upper = 2147483647;
	vector<string> res = s.findMissingRanges(nums,lower,upper);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}