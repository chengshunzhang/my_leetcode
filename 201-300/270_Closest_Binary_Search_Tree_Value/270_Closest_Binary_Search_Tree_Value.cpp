#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int result = root -> val;
        double diff = abs(result - target);
        TreeNode* p = root;
        while(p) {
            double curr = abs(p -> val - target);
            if(diff > curr) {
                result = p -> val;
                diff = curr;
            }
            if(p -> val < target) {
                p = p -> right;
            } else {
                p = p -> left;
            }
        }
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(8);
    root -> left = new TreeNode(1);
    double target = 0.42;
    Solution sol;
    cout << sol.closestValue(root, target) << endl;
    return 0;
}