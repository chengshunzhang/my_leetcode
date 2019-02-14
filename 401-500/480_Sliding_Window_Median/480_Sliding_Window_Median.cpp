#include <set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        multiset<int> minHeap;
        multiset<int, greater<int>> maxHeap;
        int left = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i - left + 1 > k) {
                if(minHeap.find(nums[left]) != minHeap.end()) {
                    minHeap.erase(minHeap.find(nums[left]));
                } else {
                    maxHeap.erase(maxHeap.find(nums[left]));
                }
                left++;
            }
            if(!maxHeap.empty() && nums[i] < *maxHeap.begin()) {
                maxHeap.insert(nums[i]);
            } else if(!minHeap.empty() && nums[i] > *minHeap.begin()) {
                minHeap.insert(nums[i]);
            } else if(maxHeap.size() <= minHeap.size()) {
                maxHeap.insert(nums[i]);
            } else {
                minHeap.insert(nums[i]);
            }
            while(maxHeap.size() > minHeap.size() + 1) {
                minHeap.insert(*maxHeap.begin());
                maxHeap.erase(maxHeap.begin());
            }
            while(maxHeap.size() < minHeap.size()) {
                maxHeap.insert(*minHeap.begin());
                minHeap.erase(minHeap.begin());
            }
            if(i - left + 1 == k) {
                double median = k % 2 == 0 ? (double)*minHeap.begin() / 2. +                                                          (double)*maxHeap.begin() / 2. :
                                                (double) *maxHeap.begin();
                result.push_back(median);
            }
        }
        return result;
    }
};

int main() {
	Solution s;
	vector<int> nums = {1,3,-1,-3,5,3,6,7};
	int k = 3;
	vector<double> res = s.medianSlidingWindow(nums, k);
	for(double med : res) {
		cout << med << ' ';
	}
	cout << endl;
	return 0;
}