#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int n = nums.size();
		if(!n)
			return 0;
		int pos = n - 1, i = 0;
		while(i < pos) {
			while(nums[pos] == val)
				pos--;
			if(pos < i)
				break;
			nums[i] == val ? nums[i++] = nums[pos--] : i++;
		}
		if(i == pos)
			return nums[i] == val ? pos : pos + 1;
		else
			return pos + 1;
	}
};

int main(){
	int n[] = {1}, val = 1;
	vector<int> nums(n,n+1);
	Solution s;
	int len = s.removeElement(nums, val);
	cout << len << endl;
	for(int i = 0; i < len; i++)
		cout << nums[i] << ' ';
	cout << endl;
	return 0;
}