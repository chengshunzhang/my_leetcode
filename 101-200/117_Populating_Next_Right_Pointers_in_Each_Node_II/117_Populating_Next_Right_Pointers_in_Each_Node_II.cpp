#include <iostream>
using namespace std;

struct TreeLinkNode {
	TreeLinkNode* left;
	TreeLinkNode* right;
	TreeLinkNode* next;
	TreeLinkNode() : left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) {
            return;
        }
        TreeLinkNode* p = NULL, * nextLayer = root;
        while(1) {
            p = nextLayer;
            while(p != NULL && p -> left == NULL && p -> right == NULL) {
                p = p -> next;
            }
            if(p) {
                nextLayer = p -> left ? p -> left : p -> right;
            } else {
                break;
            }
            while(1) {
                TreeLinkNode* temp;
                if(p -> left && p -> right) {
                    p -> left -> next = p -> right;
                    temp = p -> right;
                } else {
                    temp = p -> left ? p -> left : p -> right;
                }
                p = p -> next;
                while(p != NULL && p -> left == NULL && p -> right == NULL) {
                    p = p -> next;
                }
                if(p) {
                    temp -> next = p -> left ? p -> left : p -> right;
                } else {
                    break;
                }
            }
        } 
    }
};

int main() {
	Solution s;
	TreeLinkNode* root = new TreeLinkNode;
	root -> left = new TreeLinkNode;
	root -> right = new TreeLinkNode;
	s.connect(root);
	return 0;
}