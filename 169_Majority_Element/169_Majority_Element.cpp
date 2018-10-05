#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            if(m.count(nums[i])) {
                m[nums[i]]++;
            } else {
                m[nums[i]] = 1;
            }
        }
        int max = 1 << 31, result = 1 << 31;
        for(map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if(it -> second > max) {
                max = it -> second;
                result = it -> first;
            }
        }
        return result;
    }
};

int main() {
	int n[] = {2,2,3};
	vector<int> nums(n,n+3);
	Solution s;
	cout << s.majorityElement(nums) << endl;
	return 0;
}