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
    bool isSame(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        } else if(p != NULL & q != NULL) {
            if(p -> val != q -> val) {
                return false;
            } else {
                return isSame(p -> left, q -> left) && isSame(p -> right, q -> right);
            }
        } else {
            return false;
        }
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p, q);
    }
};

int main() {
	TreeNode* root1 = new TreeNode(1);
	root1 -> right = new TreeNode(3);
	root1 -> left = new TreeNode(2);
	TreeNode* root2 = new TreeNode(1);
	root2 -> right = new TreeNode(3);
	root2 -> left = new TreeNode(2);
	Solution s;
	cout << s.isSameTree(root1, root2) << endl;
	return 0;
}