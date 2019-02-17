#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) {
            return false;
        }
        if(root -> left == NULL && root -> right == NULL && root -> val == sum) {
            return true;
        }
        return hasPathSum(root -> left, sum - root -> val) ||
            hasPathSum(root -> right, sum - root -> val);
    }
};

int main() {
	Solution s;
	vector<int> nodes = {5,4,8,11,INT_MIN,13,4,7,2,INT_MIN,INT_MIN,INT_MIN,1};
	int sum = 22;
	TreeNode* root = new TreeNode(5);
	queue<TreeNode*> q;
	q.push(root);
	int i = 1;
	while(i < nodes.size()) {
		TreeNode* temp = q.front();
		q.pop();
		if(nodes[i] != INT_MIN) {
			temp -> left = new TreeNode(nodes[i]);
			q.push(temp -> left);
		}
		i++;
		if(nodes[i] != INT_MIN) {
			temp -> right = new TreeNode(nodes[i]);
			q.push(temp -> right);
		}
		i++;
	}
	cout << s.hasPathSum(root, sum) << endl;
	return 0;
}