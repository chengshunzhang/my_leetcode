#include <vector>
#include <queue>
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
    void helper(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        helper(root -> left);
        helper(root -> right);
        TreeNode* p = root -> left;
        if(p == NULL) {
            return;
        }
        while(p -> right != NULL) {
            p = p -> right;
        }
        p -> right = root -> right;
        root -> right = root -> left;
        root -> left = NULL;
    }
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
};

int main() {
	int n[] = {1,2,5,3,4,1<<31,6}, pos = 0;
	TreeNode* root = new TreeNode(n[pos++]);
	queue<TreeNode*> q;
	q.push(root);
	while(pos < 7) {
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
	s.flatten(root);
	TreeNode* p = root;
	while(p) {
		cout << p -> val << ' ';
		p = p -> right;
	}
	cout << endl;
	return 0;
}