#include <queue>
#include <iostream>
using namespace std;

class MyStack {
private:
    queue<int> q, qs;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(qs.empty()) {
            qs.push(x);
        } else {
            q.push(qs.front());
            qs.pop();
            qs.push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(!q.empty()) {
            for(int i = 1; i < q.size(); i++) {
                q.push(q.front());
                q.pop();
            }
            qs.push(q.front());
            q.pop();
        }
        int result = qs.front();
        qs.pop();
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return qs.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return qs.empty();
    }
};

int main() {
	MyStack obj;
	obj.push(2);
	obj.push(22);
	int param1 = obj.pop();
	int param2 = obj.top();
	bool param4 = obj.empty();
	cout << param1 << endl << param2 << endl << param4 << endl;
	return 0;
}