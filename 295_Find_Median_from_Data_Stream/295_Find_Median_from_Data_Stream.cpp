#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        if(fabs(maxHeap.size() - minHeap.size()) > 1) {
            if(maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if(maxHeap.empty() && minHeap.empty()) {
            return 0.;
        }
        if(maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else if(maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.;
        } else {
            return minHeap.top();
        }
    }
};

int main() {
	MedianFinder obj;
	obj.addNum(1);
	obj.addNum(2);
	cout << obj.findMedian() << endl;
	obj.addNum(3);
	cout << obj.findMedian() << endl;
	return 0;
}