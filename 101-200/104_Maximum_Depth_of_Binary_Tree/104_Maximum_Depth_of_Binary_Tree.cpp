#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int depth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int depthL = depth(root -> left);
        int depthR = depth(root -> right);
        return 1 + (depthL > depthR ? depthL : depthR);
    }
public:
    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};

int main() {
	int n[] = {3,9,20,1<<31,1<<31,15,7};
    TreeNode* root = new TreeNode(n[0]);
    vector<TreeNode*> nodes;
    nodes.push_back(root);
    for(int i = 1; i < 7; i++) {
    	if(n[i] != (1 << 31)) {
    		TreeNode** p;
    		if(i % 2 == 1) {
    			p = & nodes[(i - 1) / 2] -> left;
    		} else {
    			p = & nodes[(i - 1) / 2] -> right;
    		}
    		*p = new TreeNode(n[i]);
    		nodes.push_back(*p);
    	}
    }
    Solution s;
    cout << s.maxDepth(root) << endl;
    return 0;
}