#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct Result {
    int size;
    int minimum;
    int maximum;
    Result(int s, int mi, int ma) : size(s), minimum(mi), maximum(ma) {}
};

class Solution {
private:
    Result helper(TreeNode* root) {
        if(root == NULL) {
            return Result(0, INT_MAX, INT_MIN);
        } else {
            Result leftRes = helper(root -> left);
            Result rightRes = helper(root -> right);
            if(root -> val > leftRes.maximum && root -> val < rightRes.minimum) {
                int nSize = leftRes.size + rightRes.size + 1;
                int nMinimum = min(root -> val, leftRes.minimum);
                int nMaximum = max(root -> val, rightRes.maximum);
                return Result(nSize, nMinimum, nMaximum);
            } else {
                return Result(max(leftRes.size, rightRes.size), INT_MIN, INT_MAX);
            }
        }
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        return helper(root).size;
    }
};

int main() {
    TreeNode* root = new TreeNode(10);
    root -> left = new TreeNode(5);
    root -> left -> left = new TreeNode(1);
    root -> left -> right = new TreeNode(8);
    root -> right = new TreeNode(15);
    root -> right -> right = new TreeNode(7);
    Solution sol;
    cout << sol.largestBSTSubtree(root) << endl;
    return 0;
}