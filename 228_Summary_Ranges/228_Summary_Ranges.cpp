#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(!nums.size()) {
            return result;
        }
        int start = 0, end = 0;
        string temp;
        while(end < nums.size() - 1) {
            if(nums[end] + 1 == nums[end + 1]) {
                end++;
            } else {
                if(start == end) {
                    temp = to_string(nums[start]);
                    result.push_back(temp);
                } else {
                    temp = to_string(nums[start]) + "->" + to_string(nums[end]);
                    result.push_back(temp);
                }
                end++;
                start = end;
            }
        }
        if(start == end) {
            temp = to_string(nums[start]);
            result.push_back(temp);
        } else {
            temp = to_string(nums[start]) + "->" + to_string(nums[end]);
            result.push_back(temp);
        }
        return result;
    }
};

int main() {
	int n[] = {0,1,2,4,5,7};
	vector<int> nums(n,n+6);
	Solution s;
	vector<string> res = s.summaryRanges(nums);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}