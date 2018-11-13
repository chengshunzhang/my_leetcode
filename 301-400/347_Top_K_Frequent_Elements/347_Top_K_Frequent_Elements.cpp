#include <queue>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

struct comp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        priority_queue<pair<int, int>, vector<pair<int, int> >, comp > heap;
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        for(unordered_map<int, int>::iterator it = hash.begin(); it != hash.end(); it++) {
            if(heap.size() < k) {
                heap.push(make_pair(it -> first, it -> second));
            } else {
                if(it -> second > heap.top().second) {
                    heap.pop();
                    heap.push(make_pair(it -> first, it -> second));
                }
            } 
        }
        vector<int> result(k);
        for(int i = 0; i < k; i++) {
            result[i] = heap.top().first;
            heap.pop();
        }
        return result;
    }
};

int main() {
	int n[] = {5,3,1,1,1,3,5,73,1};
	vector<int> nums(n,n+9);
	Solution s;
	int k = 3;
	s.topKFrequent(nums,k);
	for(int i = 0; i < k; i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
	return 0;
}