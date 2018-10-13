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
    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int hl = 0, hr = 0;
        TreeNode* lp = root, * rp = root;
        while(lp != NULL) {
            lp = lp -> left;
            hl++;
        }
        while(rp != NULL) {
            rp = rp -> right;
            hr++;
        }
        if(hl == hr) {
            return (1 << hl) - 1;
        } else {
            return countNodes(root -> left) + countNodes(root -> right) + 1;
        }
    }
};

int main() {
	int n[] = {1,2,3,4,5,6};
    TreeNode* root = new TreeNode(n[0]);
    vector<TreeNode*> nodes;
    nodes.push_back(root);
    for(int i = 1; i < 6; i++) {
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
    cout << s.countNodes(root) << endl;
	return 0;
}