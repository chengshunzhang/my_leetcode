#include <vector>
#include <stack>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> st;
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
            if(st.empty() || nums[i] < st.top()) {
                st.push(nums[i]);
            } else {
                while(!st.empty() && nums[i] > st.top()) {
                    hash[st.top()] = nums[i];
                    st.pop();
                }
                st.push(nums[i]);
            }
        }
        while(!st.empty()) {
            hash[st.top()] = -1;
            st.pop();
        }
        vector<int> result;
        for(int i = 0; i < findNums.size(); i++) {
            result.push_back(hash[findNums[i]]);
        }
        return result;
    }
};

int main() {
	int n1[] = {4,1,2}, n2[] = {1,3,4,2};
	vector<int> findNums(n1,n1+3), nums(n2,n2+4);
	Solution s;
	vector<int> res = s.nextGreaterElement(findNums, nums);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}