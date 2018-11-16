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
    void helper(TreeNode*& t1, TreeNode* t2) {
        if(t1 == NULL) {
            t1 = t2;
        } else if(t2 != NULL) {
            t1 -> val += t2 -> val;
            helper(t1 -> left, t2 -> left);
            helper(t1 -> right, t2 -> right);
        }
    }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        helper(t1, t2);
        return t1;
    }
};

void preorder(TreeNode* root) {
	if(root == NULL) {
		return;
	}
	cout << root -> val << ' ';
	preorder(root -> left);
	preorder(root -> right);
}

int main() {
	TreeNode* root1 = new TreeNode(1), * root2 = new TreeNode(2);
	root1 -> left = new TreeNode(3);
	root1 -> right = new TreeNode(2);
	root1 -> left -> left = new TreeNode(5);
	root2 -> left = new TreeNode(1);
	root2 -> right = new TreeNode(3);
	root2 -> left -> right = new TreeNode(4);
	root2 -> right -> right = new TreeNode(7);
	Solution s;
	root1 = s.mergeTrees(root1, root2);
	preorder(root1);
	return 0;
}