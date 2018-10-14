#include <iostream>
#include <stack>
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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* p = root;
        stack<TreeNode*> st;
        int count = 0;
        while(p != NULL || !st.empty()) {
            while(p != NULL) {
                st.push(p);
                p = p -> left;
            }
            if(!st.empty()) {
                p = st.top();
                st.pop();
                count++;
                if(count == k) {
                    break;
                }
                p = p -> right;
            }
        }
        return p -> val;
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
    cout << s.kthSmallest(root, 1) << endl;
	return 0;
}