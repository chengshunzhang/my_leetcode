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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> st;
        TreeNode* p = root;
        while(p != NULL || !st.empty()) {
            while(p != NULL) {
                st.push_back(p);
                p = p -> left;
            }
            if(!st.empty()) {
                p = st.back();
                st.pop_back();
                result.push_back(p -> val);
                p = p -> right;
            }
        }
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