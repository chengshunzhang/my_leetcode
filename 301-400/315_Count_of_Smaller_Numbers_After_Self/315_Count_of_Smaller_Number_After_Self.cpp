#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void mergeCount(vector<int>& counts, vector<int>& indices, vector<int>& nums, vector<int>& support, int left, int mid, int right) {
        int num = 0, l = left, r = mid + 1, pos = left;
        for(int i = left; i <= right; i++) {
            support[i] = indices[i];
        }
        while(l <= mid && r <= right) {
            if(nums[support[l]] <= nums[support[r]]) {
                counts[support[l]] += num;
                indices[pos++] = support[l++];
            } else {
                indices[pos++] = support[r++];
                num++;
            }
        }
        while(l <= mid) {
            counts[support[l]] += num;
            indices[pos++] = support[l++];
        }
        while(r <= right) {
            indices[pos++] = support[r++];
        }
    }
    void mergeSort(vector<int>& counts, vector<int>& indices, vector<int>& nums, vector<int>& support, int left, int right) {
        if(left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(counts, indices, nums, support, left, mid);
        mergeSort(counts, indices, nums, support, mid + 1, right);
        mergeCount(counts, indices, nums, support, left, mid, right);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts(nums.size(), 0), indices(nums.size()), support(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            indices[i] = i;
        }
        mergeSort(counts, indices, nums, support, 0, nums.size() - 1);
        return counts;
    }
};

int main() {
	int n[] = {5,2,6,1};
	vector<int> nums(n,n+4), res;
	Solution s;
	res = s.countSmaller(nums);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}