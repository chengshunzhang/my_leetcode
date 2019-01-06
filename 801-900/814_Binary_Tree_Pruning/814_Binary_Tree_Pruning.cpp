#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool pruneHelper(TreeNode*& root) {
        if(root == NULL) {
            return false;
        }
        bool leftOne = false, rightOne = false;
        leftOne = pruneHelper(root -> left);
        rightOne = pruneHelper(root -> right);
        if(leftOne || rightOne || root -> val == 1) {
            return true;
        } else {
            delete root;
            root = NULL;
            return false;
        }
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        pruneHelper(root);
        return root;
    }
};

void preOrder(TreeNode* root) {
	if(root == NULL) {
		return;
	}
	cout << root -> val << ',';
	preOrder(root -> left);
	preOrder(root -> right);
}

int main() {
	int n[] = {1, INT_MAX, 0, 0, 1};
	vector<int> nodes(n, n + 5);
	int pos = 0;
	TreeNode* root = new TreeNode(nodes[pos++]);
	queue<TreeNode*> q;
	q.push(root);
	while(pos < nodes.size()) {
		TreeNode* temp = q.front();
		q.pop();
		if(nodes[pos] != INT_MAX) {
			temp -> left = new TreeNode(nodes[pos]);
			q.push(temp -> left);
		}
		pos++;
		if(nodes[pos] != INT_MAX) {
			temp -> right = new TreeNode(nodes[pos]);
			q.push(temp -> right);
		}
		pos++;
	}
	Solution s;
	root = s.pruneTree(root);
	preOrder(root);
	cout << "\b \b" << endl;
	return 0;
}