#include <queue>
#include <iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode* left;
	TreeLinkNode* right;
	TreeLinkNode* next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL || root -> left == NULL) {
            return;
        }
        root -> left -> next = root -> right;
        TreeLinkNode* p = root -> left;
        while(p -> left != NULL) {
            TreeLinkNode* q = p;
            while(q -> next != NULL) {
                q -> left -> next = q -> right;
                q -> right -> next = q -> next -> left;
                q = q -> next;
            }
            q -> left -> next = q -> right;
            p = p -> left;
        }
    }
};

int main() {
	int n[] = {1,2,3,4,5,6,7}, pos = 1;
    TreeLinkNode* root = new TreeLinkNode(n[0]);
    queue<TreeLinkNode*> q;
    q.push(root);
    while(pos < 7) {
    	TreeLinkNode* temp = q.front();
    	q.pop();
    	if(n[pos] != (1<<31)) {
    		temp -> left = new TreeLinkNode(n[pos]);
    		q.push(temp -> left);
    	}
    	pos++;
    	if(n[pos] != (1<<31)) {
    		temp -> right = new TreeLinkNode(n[pos]);
    		q.push(temp -> right);
    	}
    	pos++;
    }
    Solution s;
    s.connect(root);
	return 0;
}