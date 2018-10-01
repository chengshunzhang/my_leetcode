#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool helper(TreeNode* l, TreeNode* r) {
        if(l == NULL && r == NULL) {
            return true;
        }
        if(l == NULL || r == NULL) {
            return false;
        }
        if(l -> val == r -> val) {
            return helper(l -> left, r -> right) && helper(l -> right, r -> left);
        } else {
            return false;
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        return helper(root -> left, root -> right);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root -> right = new TreeNode(3);
    root -> left = new TreeNode(2);
    Solution s;
    cout << s.isSymmetric(root) << endl;
    return 0;
}