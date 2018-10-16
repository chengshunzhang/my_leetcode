#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }
        if(root == p) {
            return p;
        }
        if(root == q) {
            return q;
        }
        TreeNode* l = lowestCommonAncestor(root -> left, p, q);
        TreeNode* r = lowestCommonAncestor(root -> right, p, q);
        if(l != NULL && r != NULL) {
            return root;
        }
        if(l == NULL) {
            return r;
        }
        return l;
    }
};

int main() {
	int n[] = {3,5,1,6,2,0,8,1<<31,1<<31,7,4};
    TreeNode* root = new TreeNode(n[0]);
    vector<TreeNode*> nodes;
    nodes.push_back(root);
    for(int i = 1; i < 11; i++) {
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
    TreeNode* p = nodes[1], * q = nodes[2];
    Solution s;
    TreeNode* newroot = s.lowestCommonAncestor(root, p, q);
    cout << newroot -> val << endl;
	return 0;
}