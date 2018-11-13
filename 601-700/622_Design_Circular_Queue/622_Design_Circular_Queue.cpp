#include <vector>
#include <iostream>
using namespace std;

class MyCircularQueue {
    private:
    vector<int> myQueue;
    int front, rear, queueSize;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        myQueue.resize(k + 1);
        queueSize = k + 1;
        front = rear = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(!isFull()) {
            myQueue[rear] = value;
            rear = (rear + 1) % queueSize;
            return true;
        } else {
            return false;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) {
            return false;
        } else {
            front = (front + 1) % queueSize;
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) {
            return -1;
        } else {
            return myQueue[front];
        }
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) {
            return -1;
        } else {
            return myQueue[(rear + queueSize - 1) % queueSize];
        }
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(rear == front) {
            return true;
        } else {
            return false;
        }
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if((rear + 1) % queueSize == front) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
	MyCircularQueue obj(3);
	cout << obj.enQueue(1) << endl;
	cout << obj.enQueue(2) << endl;
	cout << obj.enQueue(3) << endl;
	cout << obj.enQueue(4) << endl;
	cout << obj.Rear() << endl;
	cout << obj.isFull() << endl;
	cout << obj.deQueue() << endl;
	cout << obj.enQueue(4) << endl;
	cout << obj.Rear() << endl;
	return 0;
}