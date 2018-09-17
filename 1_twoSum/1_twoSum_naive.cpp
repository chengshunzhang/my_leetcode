#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        bool find = false;
    	vector<int> result(2);
        for (int i = 0; i < nums.size(); i++){
        	int num = target - nums[i];
        	for (int j = i + 1; j < nums.size(); j++){
        		if (nums[j] == num){
        			result[0] = i; result[1] = j;
                    find = true;
                    break;
        		}
        	}
            if (find == true)
                break;
        }
        return result;
    }
};

int main(){
    int nums_arr[] = {2,7,11,15};
	vector<int> nums(nums_arr, nums_arr + 4);
	int target = 9;
	Solution s;
	vector<int> result = s.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
	return 0;
}