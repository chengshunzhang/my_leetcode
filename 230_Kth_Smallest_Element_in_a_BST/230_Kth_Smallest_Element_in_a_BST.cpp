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
private:
	int numOfNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        } else {
            return 1 + numOfNodes(root -> left) + numOfNodes(root -> right);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int n = numOfNodes(root -> left);
        if(n == k - 1) {
            return root -> val;
        } else if(n >= k) {
            return kthSmallest(root -> left, k);
        } else {
            return kthSmallest(root -> right, k - n - 1);
        }
    }
};

int main() {
	int n[] = {3,1,4,1<<31,2};
    TreeNode* root = new TreeNode(n[0]);
    vector<TreeNode*> nodes;
    nodes.push_back(root);
    for(int i = 1; i < 5; i++) {
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
    cout << s.kthSmallest(root, 2) << endl;
	return 0;
}