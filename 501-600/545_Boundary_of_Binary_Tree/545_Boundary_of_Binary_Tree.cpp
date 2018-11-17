#include <vector>
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
    void findLeaves(TreeNode* root, vector<int>& result) {
        if(root == NULL) {
            return;
        }
        if(root -> left == NULL && root -> right == NULL) {
            result.push_back(root -> val);
            return;
        }
        findLeaves(root -> left, result);
        findLeaves(root -> right, result);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        result.push_back(root -> val);
        if(root -> left == NULL && root -> right == NULL) {
            return result;
        }
        TreeNode* p = root -> left;
        while(p != NULL && (p -> left || p -> right)) {
            result.push_back(p -> val);
            p = (p -> left == NULL ? p -> right : p -> left);
        }
        findLeaves(root, result);
        vector<int> rightBound;
        p = root -> right;
        while(p != NULL && (p -> left || p -> right)) {
            rightBound.push_back(p -> val);
            p = (p -> right == NULL ? p -> left : p -> right);
        }
        if(rightBound.empty()) {
            return result;
        }
        for(int i = rightBound.size() - 1; i >= 0; i--) {
            result.push_back(rightBound[i]);
        }
        return result;
    }
};

int main() {
	TreeNode* root = new TreeNode(1);
	root -> right = new TreeNode(2);
	root -> right -> left = new TreeNode(3);
	root -> right -> right = new TreeNode(4);
	Solution s;
	vector<int> result = s.boundaryOfBinaryTree(root);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	cout << endl;
	return 0;
}