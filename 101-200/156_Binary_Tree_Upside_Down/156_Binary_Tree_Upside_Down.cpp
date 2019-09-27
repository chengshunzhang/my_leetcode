// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        stack<TreeNode*> st;
        TreeNode* p = root;
        st.push(p);
        while(p -> left) {
            p = p -> left;
            st.push(p);
        }
        TreeNode* newRoot = new TreeNode(st.top() -> val);
        TreeNode* curr = newRoot;
        st.pop();
        while(!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            if(temp -> right) {
                curr -> left = new TreeNode(temp -> right -> val);
            }
            curr -> right = new TreeNode(temp -> val);
            curr = curr -> right;
        }
        return newRoot;
    }
};