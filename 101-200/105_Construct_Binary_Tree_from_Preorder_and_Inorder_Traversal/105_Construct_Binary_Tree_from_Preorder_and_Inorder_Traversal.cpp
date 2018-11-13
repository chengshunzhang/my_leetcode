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
    void buildHelper(TreeNode*& root, vector<int>& preorder, vector<int>& inorder, int left, int right, int& pre) {
        root = new TreeNode(preorder[pre]);
        int in = left;
        while(inorder[in] != preorder[pre]) {
            in++;
        }
        if(left < in) {
            buildHelper(root -> left, preorder, inorder, left, in - 1, ++pre);
        }
        if(in < right) {
            buildHelper(root -> right, preorder, inorder, in + 1, right, ++pre);
        } 
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = NULL;
        int r = inorder.size() - 1, pre = 0;
        if(r < 0) {
            return root;
        }
        buildHelper(root, preorder, inorder, 0, r, pre);
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