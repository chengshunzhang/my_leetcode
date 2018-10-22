#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) {
            return true;
        }
        TreeNode* p = root;
        stack<TreeNode*> st;
        int first, second;
        bool empty = true;
        while(p != NULL || !st.empty()) {
            if(p == NULL) {
                p = st.top();
                st.pop();
                if(empty) {
                    first = p -> val;
                    empty = false;
                } else {
                    second = p -> val;
                    if(first >= second) {
                        return false;
                    }
                    first = second;
                }
                p = p -> right;
            } else {
                st.push(p);
                p = p -> left;
            }
        }
        return true;
    }
};

int main() {
	TreeNode* root = new TreeNode(2);
	root -> left = new TreeNode(1);
	root -> right = new TreeNode(3);
	Solution s;
	cout << s.isValidBST(root) << endl;
	return 0;
}