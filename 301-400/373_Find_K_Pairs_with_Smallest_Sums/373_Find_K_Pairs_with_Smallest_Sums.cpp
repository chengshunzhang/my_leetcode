#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int> > result;
        int m = nums1.size(), n = nums2.size(), iterations = min(m * n, k);
        vector<int> start(nums1.size(), 0);
        for(int i = 0; i < iterations; i++) {
            int pos = -1, sum = ((uint)1 << 31) - 1;
            for(int j = 0; j < nums1.size(); j++) {
                if(start[j] < nums2.size() && nums1[j] + nums2[start[j]] < sum) {
                    sum = nums1[j] + nums2[start[j]];
                    pos = j;
                }
            }
            result.push_back(make_pair(nums1[pos], nums2[start[pos]]));
            start[pos]++;
        }
        return result;
    }
};

int main() {
	int n1[] = {1,7,11}, n2[] = {2,4,6};
	vector<int> nums1(n1,n1+3), nums2(n2,n2+3);
	Solution s;
	int k = 3;
	vector<pair<int, int> > res = s.kSmallestPairs(nums1, nums2, k);
	for(int i = 0; i < res.size(); i++) {
		cout << '[' << res[i].first << ',' << res[i].second << "] ";
	}
	cout << endl;
	return 0;
}