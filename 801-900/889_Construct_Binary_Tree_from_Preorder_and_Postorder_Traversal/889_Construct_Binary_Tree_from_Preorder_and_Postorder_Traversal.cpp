#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void constructHelper(TreeNode*& root, vector<int>& pre, vector<int>& post, int left, int right, int& prePos) {
        root = new TreeNode(post[right]);
        int p = right - 1;
        while(p >= left && post[p] != pre[prePos]) {
            p--;
        }
        if(p >= left) {
            constructHelper(root -> left, pre, post, left, p, ++prePos);
        }
        if(p < right - 1) {
            constructHelper(root -> right, pre, post, p + 1, right - 1, ++prePos);
        }
    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* root;
        int prePos = 1;
        constructHelper(root, pre, post, 0, pre.size() - 1, prePos);
        return root;
    }
};

void levelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()) {
		TreeNode* temp = q.front();
		q.pop();
		cout << temp -> val << ',';
		if(temp -> left) {
			q.push(temp -> left);
		}
		if(temp -> right) {
			q.push(temp -> right);
		}
	}
	cout << "\b \b" << endl;
}

int main() {
	vector<int> pre = {1,2,4,5,3,6,7}, post = {4,5,2,6,7,3,1};
	Solution s;
	TreeNode* root = s.constructFromPrePost(pre, post);
	levelOrder(root);
	return 0;
}