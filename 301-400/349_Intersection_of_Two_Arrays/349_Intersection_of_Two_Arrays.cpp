#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, bool> hash;
        for(int i = 0; i < nums1.size(); i++) {
            hash[nums1[i]] = true;
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(hash.count(nums2[i])) {
                hash.erase(hash.find(nums2[i]));
                result.push_back(nums2[i]);
            }
        }
        return result;
    }
};

int main() {
	int n1[] = {1,2,2,1}, n2[] = {2,2};
	vector<int> nums1(n1,n1+4), nums2(n2,n2+2);
	Solution s;
	vector<int> res = s.intersection(nums1, nums2);
	for(int i= 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}