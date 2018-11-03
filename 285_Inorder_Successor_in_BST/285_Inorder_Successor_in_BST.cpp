#include <stack>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p -> right == NULL) {
            stack<TreeNode*> st;
            TreeNode* q = root;
            bool find = false;
            while(q != NULL || !st.empty()) {
                while(q != NULL) {
                    st.push(q);
                    q = q -> left;
                }
                if(!st.empty()) {
                    q = st.top();
                    if(find) {
                        return q;
                    }
                    st.pop();
                    if(q == p) {
                        find = true;
                    }
                    q = q -> right;
                }
            }
            return NULL;
        } else {
            TreeNode* q = p -> right;
            while(q -> left != NULL) {
                q = q -> left;
            }
            return q;
        }
    }
};

int main() {
	int n[] = {5,3,6,2,4,1<<31,1<<31,1}, pos = 0;
	queue<TreeNode*> q;
	TreeNode* root = new TreeNode(n[pos++]);
	q.push(root);
	while(pos < 8) {
		TreeNode* temp = q.front();
		q.pop();
		if(n[pos] != (1<<31)) {
			temp -> left = new TreeNode(n[pos]);
			q.push(temp -> left);
		}
		pos++;
		if(n[pos] != (1<<31)) {
			temp -> right = new TreeNode(n[pos]);
			q.push(temp -> right);
		}
		pos++;
	}
	Solution s;
	TreeNode* res = s.inorderSuccessor(root, root -> right);
	if(res != NULL) {
		cout << res -> val << endl;
	} else {
		cout << "NULL" << endl;
	}
	return 0;
}