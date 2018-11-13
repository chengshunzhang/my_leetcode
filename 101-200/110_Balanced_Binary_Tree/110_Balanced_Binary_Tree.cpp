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
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int hl = height(root -> left), hr = height(root -> right);
        return 1 + (hl > hr ? hl : hr);
    }
    bool helper(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        int h_left = height(root -> left), h_right = height(root -> right);
        int diff = h_left - h_right;        
        if(diff < -1 || diff > 1) {
            return false;
        } else {
            return helper(root -> left) && helper(root -> right);
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        return helper(root);
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
    cout << s.isBalanced(root) << endl;
    return 0;
}