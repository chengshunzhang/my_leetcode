#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.empty()) {
            return true;
        }
        int low = INT_MIN;
        stack<int> s;
        s.push(preorder[0]);
        for(int i = 1; i < preorder.size(); i++) {
            if(preorder[i] < low) {
                return false;
            }
            if(preorder[i] < s.top()) {
                s.push(preorder[i]);
            } else {
                while(!s.empty() && preorder[i] > s.top()) {
                    low = s.top();
                    s.pop();
                }
                s.push(preorder[i]);
            }
        }
        return true;
    }
};

int main() {
    vector<int> preorder = {5, 2, 6, 1, 3};
    Solution sol;
    cout << sol.verifyPreorder(preorder) << endl;
    return 0;
}