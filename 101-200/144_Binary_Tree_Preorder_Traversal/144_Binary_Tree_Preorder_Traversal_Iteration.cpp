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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        vector<TreeNode*> st;
        TreeNode* p = root;
        while(p != NULL || !st.empty()) {
            if(p == NULL) {
                p = st.back();
                st.pop_back();
            }
            result.push_back(p -> val);
            if(p -> right != NULL) {
                st.push_back(p -> right);
            }
            p = p -> left;
        }
        return result;
    }
};

int main() {
	int n[] = {1,1<<31,2,3};
    TreeNode* root = new TreeNode(n[0]);
    vector<TreeNode*> nodes;
    nodes.push_back(root);
    for(int i = 1; i < 4; i++) {
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
    vector<int> res = s.preorderTraversal(root);
    for(int i = 0; i < res.size(); i++) {
    	cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}