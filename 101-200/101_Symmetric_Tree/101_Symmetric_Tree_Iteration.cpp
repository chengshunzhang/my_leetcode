#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) {
            return true;
        }
        if(root -> left == NULL || root -> right == NULL) {
            return false;
        }
        TreeNode* l = root -> left, * r = root -> right;
        vector<TreeNode*> stLeft, stRight;
        while((l != NULL && r != NULL) || !stLeft.empty()) {
            if(l == NULL && r == NULL) {
                l = stLeft.back();
                r = stRight.back();
                stLeft.pop_back();
                stRight.pop_back();
            }
            if(l == NULL || r == NULL || l -> val != r -> val) {
                return false;
            }
            if(l -> right != NULL && r -> left != NULL) {
                stLeft.push_back(l -> right);
                stRight.push_back(r -> left);
            } else if((l -> right == NULL && r -> left != NULL) || (l -> right != NULL && r -> left == NULL)) {
                return false;
            }
            l = l -> left;
            r = r -> right;
        }
        return true;
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