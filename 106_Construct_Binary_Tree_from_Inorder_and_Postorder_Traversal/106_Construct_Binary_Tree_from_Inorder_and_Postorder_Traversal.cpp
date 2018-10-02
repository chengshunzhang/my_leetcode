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
    void buildHelper(TreeNode*& root, vector<int>& inorder, vector<int>& postorder, int left, int right, int& pos) {
        root = new TreeNode(postorder[pos]);
        int in = left;
        while(inorder[in] != postorder[pos]) {
            in++;
        }
        if(in < right) {
            buildHelper(root -> right, inorder, postorder, in + 1, right, --pos);
        }
        if(left < in) {
            buildHelper(root -> left, inorder, postorder, left, in - 1, --pos);
        }
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int r = inorder.size() - 1;
        if(r < 0) {
            return NULL;
        }
        TreeNode* root = NULL;
        buildHelper(root, inorder, postorder, 0, r, r);
        return root;
    }
};

int main() {
	int p[] = {3,9,20,15,7}, i[] = {9,3,15,20,7};
	vector<int> preorder(p,p+5), inorder(i,i+5);
	Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);
    return 0;
}