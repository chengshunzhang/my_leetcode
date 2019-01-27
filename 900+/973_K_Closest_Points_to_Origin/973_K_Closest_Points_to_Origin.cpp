#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct myComp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, myComp> maxHeap;
        for(int i = 0; i < points.size(); i++) {
            maxHeap.push(points[i]);
            if(i >= K) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> result;
        while(!maxHeap.empty()) {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return result;
    }
};

int main() {
	Solution s;
	vector<vector<int>> points = {{1, 3}, {-2, 2}};
	int K = 1;
	vector<vector<int>> res = s.kClosest(points, K);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i][0] << ',' << res[i][1] << endl;
	}
	return 0;
}