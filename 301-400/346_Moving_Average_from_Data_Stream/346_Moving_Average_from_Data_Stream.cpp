#include <queue>
#include <iostream>
using namespace std;

class MovingAverage {
private:
    queue<int> q;
    int windowSize, sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        windowSize = size;
        sum = 0;
    }
    
    double next(int val) {
        if(q.size() == windowSize) {
            sum -= q.front();
            q.pop();
        }
        sum += val;
        q.push(val);
        return (double)sum / q.size();
    }
};

int main() {
	MovingAverage obj(3);
	cout << obj.next(1) << endl;
	cout << obj.next(10) << endl;
	cout << obj.next(3) << endl;
	cout << obj.next(5) << endl;
	return 0;
}