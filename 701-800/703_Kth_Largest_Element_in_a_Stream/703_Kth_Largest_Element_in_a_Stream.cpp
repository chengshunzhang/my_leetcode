#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int k;
public:
    KthLargest(int k, vector<int> nums) {
        this -> k = k;
        for(int i = 0; i < nums.size(); i++) {
            minHeap.push(nums[i]);
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        if(minHeap.size() < k) {
            minHeap.push(val);
        } else if(val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};

int main() {
	int n[] = {4,5,8,2};
	vector<int> nums(n,n+4);
	KthLargest obj(3, nums);
	cout << obj.add(3) << endl;
	cout << obj.add(5) << endl;
	cout << obj.add(10) << endl;
	cout << obj.add(9) << endl;
	cout << obj.add(4) << endl;
	return 0;
}