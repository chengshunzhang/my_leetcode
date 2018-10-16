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
        if(root -> val > p -> val && root -> val > q -> val) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        if(root -> val < p -> val && root -> val < q -> val) {
            return lowestCommonAncestor(root -> right, p, q);
        }
        return root;
    }
};

int main() {
	int n[] = {6,2,8,0,4,7,9,1<<31,1<<31,3,5};
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