#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int helper(TreeNode* root) {
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) {
            return ((uint)1 << 31) - 1;
        }
        int diff = ((uint)1 << 31) - 1;
        if(root -> left) {
            TreeNode* p = root -> left;
            while(p -> right) {
                p = p -> right;
            }
            diff = root -> val - p -> val;
        }
        if(root -> right) {
            TreeNode* p = root -> right;
            while(p -> left) {
                p = p -> left;
            }
            if(p -> val - root -> val < diff) {
                diff = p -> val - root -> val;
            }
        }
        if(diff == 1) {
            return diff;
        }
        int leftPart = helper(root -> left);
        int rightPart = helper(root -> right);
        return min(diff, min(leftPart, rightPart));
    }
public:
    int minDiffInBST(TreeNode* root) {
        return helper(root);
    }
};

int main() {
	TreeNode* root = new TreeNode(27);
	root -> right = new TreeNode(34);
	root -> right -> right = new TreeNode(58);
	root -> right -> right -> left = new TreeNode(50);
	root -> right -> right -> left -> left = new TreeNode(44);
	Solution s;
	cout << s.minDiffInBST(root) << endl;
	return 0;
}