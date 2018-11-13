#include <vector>
#include <iostream>
using namespace std;

class MinStack {
private:
    vector<int> st;
    vector<int> min;
public:
    MinStack() {
    }
    
    void push(int x) {
        st.push_back(x);
        if(min.empty() || x <= min.back()) {
            min.push_back(x);
        }
    }
    
    void pop() {
        if(!min.empty() && st.back() == min.back()) {
            min.pop_back();
        }
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return min.back();
    }
};

int main() {
	MinStack obj;
	obj.push(3);
	obj.push(2);
	obj.pop();
	cout << obj.getMin() << endl;
	return 0;
}