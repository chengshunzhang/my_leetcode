#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        TreeNode* newRoot = root;
        while(newRoot -> val < L || newRoot -> val > R) {
            if(newRoot -> val < L) {
                newRoot = newRoot -> right;
            } else {
                newRoot = newRoot -> left;
            }
        }
        TreeNode* l = newRoot, * r = newRoot;
        while(l -> left != NULL) {
            if(l -> left -> val < L) {
                l -> left = l -> left -> right;
            } else {
                l = l -> left;
            }
        }
        while(r -> right != NULL) {
            if(r -> right -> val > R) {
                r -> right = r -> right -> left;
            } else {
                r = r -> right;
            }
        }
        return newRoot;
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
	int n[] = {1,0,2}, pos = 0;
	queue<TreeNode*> q;
	TreeNode* root = new TreeNode(n[pos++]);
	q.push(root);
	while(pos < 3) {
		TreeNode* temp = q.front();
		q.pop();
		if(n[pos] != (1<<31)) {
			temp -> left = new TreeNode(n[pos]);
			q.push(temp -> left);
		}
		pos++;
		if(n[pos] != (1<<31)) {
			temp -> right = new TreeNode(n[pos]);
			q.push(temp -> right);
		}
		pos++;
	}
	Solution s;
	TreeNode* res = s.trimBST(root, 1, 2);
	preOrder(res);
	cout << endl;
	return 0;
}