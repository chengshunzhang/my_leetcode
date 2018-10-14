#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        if(!n) {
            return result;
        }
        int candidate1 = 0, candidate2 = 1, count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == candidate1) {
                count1++;
            } else if(nums[i] == candidate2) {
                count2++;
            } else if(count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            } else if(count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == candidate1) {
                count1++;
            }
            if(nums[i] == candidate2) {
                count2++;
            }
        }
        if(count1 > n / 3) {
            result.push_back(candidate1);
        }
        if(count2 > n / 3) {
            result.push_back(candidate2);
        }
        return result;
    }
};

int main() {
	int n[] = {3,2,3};
	vector<int> nums(n,n+3);
	Solution s;
	vector<int> res = s.majorityElement(nums);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}