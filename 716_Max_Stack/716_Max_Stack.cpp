#include <stack>
#include <iostream>
using namespace std;

class MaxStack {
    stack<int> orderSt;
    stack<int> maxSt;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        orderSt.push(x);
        if(maxSt.empty() || x >= maxSt.top()) {
            maxSt.push(x);
        }
    }
    
    int pop() {
        int top = orderSt.top();
        orderSt.pop();
        if(!maxSt.empty() && maxSt.top() == top) {
            maxSt.pop();
        }
        return top;
    }
    
    int top() {
        return orderSt.top();
    }
    
    int peekMax() {
        return maxSt.top();
    }
    
    int popMax() {
        int maximum = maxSt.top();
        maxSt.pop();
        stack<int> temp;
        while(orderSt.top() != maximum) {
            temp.push(orderSt.top());
            orderSt.pop();
        }
        orderSt.pop();
        while(!temp.empty()) {
            push(temp.top());
            temp.pop();
        }
        return maximum;
    }
};

int main() {
	MaxStack myStack;
	myStack.push(5); 
	myStack.push(1);
	myStack.push(5);
	cout << myStack.top() << endl; //-> 5
	cout << myStack.popMax() << endl; //-> 5
	cout << myStack.top() << endl; //-> 1
	cout << myStack.peekMax() << endl; //-> 5
	cout << myStack.pop() << endl;// -> 1
	cout << myStack.top() << endl;// -> 5
	return 0;
}