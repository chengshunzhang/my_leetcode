#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.empty()) {
            return true;
        }
        int low = INT_MIN, left = 0, top = 0;
        for(int i = 1; i < preorder.size(); i++) {
            if(preorder[i] < low) {
                return false;
            }
            if(preorder[i] < preorder[top]) {
                top++;
            } else {
                while(top >= left && preorder[i] > preorder[top]) {
                    low = preorder[top];
                    top--;
                }
                if(top < left) {
                    left = i;
                }
                top = i;
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