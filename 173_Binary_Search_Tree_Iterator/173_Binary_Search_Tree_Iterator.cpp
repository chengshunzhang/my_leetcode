#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        TreeNode* temp = root;
        while(temp != NULL) {
            st.push(temp);
            temp = temp -> left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(!st.empty()) {
            return true;
        } else {
            return false;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* smallest = st.top();
        st.pop();
        if(smallest -> right != NULL) {
            TreeNode* p = smallest -> right;
            while(p != NULL) {
                st.push(p);
                p = p -> left;
            }
        }
        return smallest -> val;
    }
};

int main() {
	TreeNode* root = new TreeNode(1);
	BSTIterator i(root);
	while(i.hasNext()) {
		cout << i.next() << endl;
	}
	return 0;
}