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
    pair<bool, int> countHelper(TreeNode* root, int& result) {
        if(root -> left == NULL && root -> right == NULL) {
            result++;
            return make_pair(true, root -> val);
        } else if(root -> left == NULL) {
            pair<bool, int> rightRes = countHelper(root -> right, result);
            if(rightRes.first && root -> val == rightRes.second) {
                result++;
                return make_pair(true, root -> val);
            } else {
                return make_pair(false, 0);
            }
        } else if(root -> right == NULL) {
            pair<bool, int> leftRes = countHelper(root -> left, result);
            if(leftRes.first && root -> val == leftRes.second) {
                result++;
                return make_pair(true, root -> val);
            } else {
                return make_pair(false, 0);
            }
        } else {
            pair<bool, int> rightRes = countHelper(root -> right, result);
            pair<bool, int> leftRes = countHelper(root -> left, result);
            if(leftRes.first && rightRes.first && root -> val == leftRes.second && root -> val == rightRes.second) {
                result++;
                return make_pair(true, root -> val);
            } else {
                return make_pair(false, 0);
            }
        }
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int result = 0;
        countHelper(root, result);
        return result;
    }
};

int main() {
	TreeNode* root = new TreeNode(5);
	root -> left = new TreeNode(1);
	root -> left -> left = new TreeNode(5);
	root -> left -> right = new TreeNode(5);
	root -> right = new TreeNode(5);
	root -> right -> right = new TreeNode(5);
	Solution s;
	cout << s.countUnivalSubtrees(root) << endl;
	return 0;
}