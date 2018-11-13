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
    bool helper(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL) {
            return true;
        }
        if(s == NULL || t == NULL) {
            return false;
        }
        if(s -> val == t -> val) {
            return helper(s -> left, t -> left) && helper(s -> right, t -> right);
        } else {
            return false;
        }
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL) {
            return true;
        }
        if(s == NULL || t == NULL) {
            return false;
        }
        if(s -> val == t -> val && helper(s -> left, t -> left) && helper(s -> right, t -> right)) {
            return true;
        } else {
            return isSubtree(s -> left, t) || isSubtree(s -> right, t);
        }
    }
};

int main() {
	TreeNode* s = new TreeNode(3);
	s -> left = new TreeNode(4);
	s -> right = new TreeNode(5);
	s -> left -> left = new TreeNode(1);
	s -> left -> right = new TreeNode(2);
	TreeNode* t = new TreeNode(4);
	t -> left = new TreeNode(1);
	t -> right = new TreeNode(2);
	Solution sol;
	cout << sol.isSubtree(s, t) << endl;
	return 0;
}