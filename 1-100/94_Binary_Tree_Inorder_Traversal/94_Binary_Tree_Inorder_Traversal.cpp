#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void inTraverse(TreeNode* root, vector<int>& result) {
        if(root == NULL) {
            return;
        }
        inTraverse(root -> left, result);
        result.push_back(root -> val);
        inTraverse(root -> right, result);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inTraverse(root, result);
        return result;
    }
};

int main() {
	TreeNode* root = new TreeNode(1);
	root -> right = new TreeNode(2);
	root -> right -> left = new TreeNode(3);
	Solution s;
	vector<int> res = s.inorderTraversal(root);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}