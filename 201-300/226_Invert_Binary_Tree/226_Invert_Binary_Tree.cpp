#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode* root) {
	if(root == NULL) {
		return;
	}
	cout << root -> val << ' ';
	preOrder(root -> left);
	preOrder(root -> right);
}

class Solution {
private:
    void invertHelper(TreeNode*& root) {
        if(root == NULL) {
            return;
        }
        TreeNode* temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
        invertHelper(root -> left);
        invertHelper(root -> right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        invertHelper(root);
        return root;
    }
};

int main() {
	int n[] = {4,2,7,1,3,6,9};
    TreeNode* root = new TreeNode(n[0]);
    vector<TreeNode*> nodes;
    nodes.push_back(root);
    for(int i = 1; i < 7; i++) {
    	if(n[i] != (1 << 31)) {
    		TreeNode* p = new TreeNode(n[i]);
    		if(i % 2 == 1) {
    			nodes[(i - 1) / 2] -> left = p;
    		} else {
    			nodes[(i - 1) / 2] -> right = p;
    		}
    		nodes.push_back(p);
    	}
    }
    Solution s;
    TreeNode* newroot = s.invertTree(root);
    preOrder(newroot);
    cout << endl;
	return 0;
}