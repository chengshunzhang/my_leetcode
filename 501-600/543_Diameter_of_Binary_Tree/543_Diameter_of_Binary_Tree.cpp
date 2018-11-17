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
    int helper(TreeNode* root, int& result) {
        if(root == NULL) {
            return -1;
        }
        int leftLen = helper(root -> left, result) + 1;
        int rightLen = helper(root -> right, result) + 1;
        int d = leftLen + rightLen;
        if(d > result) {
            result = d;
        }
        return max(leftLen, rightLen);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        helper(root, result);
        return result;
    }
};

int main() {
	TreeNode* root = new TreeNode(1);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(3);
	root -> left -> left = new TreeNode(4);
	root -> left -> right = new TreeNode(5);
	Solution s;
	cout << s.diameterOfBinaryTree(root) << endl;
	return 0;
}