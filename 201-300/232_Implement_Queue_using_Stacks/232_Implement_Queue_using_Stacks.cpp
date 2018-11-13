#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
private:
    stack<int> stStore;
    stack<int> stPop;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stStore.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stPop.empty()) {
            while(!stStore.empty()) {
                int a = stStore.top();
                stStore.pop();
                stPop.push(a);
            }
        }
        int result = stPop.top();
        stPop.pop();
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        if(stPop.empty()) {
            while(!stStore.empty()) {
                int a = stStore.top();
                stStore.pop();
                stPop.push(a);
            }
        }
        return stPop.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stStore.empty() && stPop.empty();
    }
};

int main() {
	MyQueue obj;
	obj.push(5);
	obj.push(2);
	cout << obj.pop() << endl;
	cout << obj.peek() << endl;
	cout << obj.empty() << endl;
	return 0;
}