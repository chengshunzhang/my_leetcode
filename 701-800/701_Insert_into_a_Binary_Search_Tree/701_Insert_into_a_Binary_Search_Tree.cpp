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
    void insertHelper(TreeNode*& root, int val) {
        if(root == NULL) {
            root = new TreeNode(val);
            return;
        }
        if(val < root -> val) {
            insertHelper(root -> left, val);
        } else {
            insertHelper(root -> right, val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insertHelper(root, val);
        return root;
    }
};

void preOrder(TreeNode* root) {
	if(root == NULL) {
		return;
	}
	cout << root -> val << ' ';
	preOrder(root -> left);
	preOrder(root -> right);
}

int main() {
	TreeNode* root = new TreeNode(4);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(7);
	root -> left -> left = new TreeNode(1);
	root -> left -> right = new TreeNode(3);
	Solution s;
	int val = 5;
	s.insertIntoBST(root, val);
	preOrder(root);
	cout << endl;
	return 0;
}