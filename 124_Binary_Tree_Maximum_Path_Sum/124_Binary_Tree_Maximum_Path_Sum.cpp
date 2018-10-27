#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

class Solution {
private:
    pair<int, int> sumHelper(TreeNode* root) {
        if(root == NULL) {
            return make_pair(0, 0);
        }
        pair<int, int> left = sumHelper(root -> left), right = sumHelper(root -> right);
        pair<int, int> res;
        res.first = max(root -> val, max(root -> val + left.first, root -> val + right.first));
        res.second = max(max(max(left.first, left.second), max(right.first, right.second)), root -> val + left.first + right.first);
        return res;
    }
    void preOrder(TreeNode* root, int& maxi) {
        if(root == NULL) {
            return;
        }
        if(root -> val > maxi) {
            maxi = root -> val;
        }
        preOrder(root -> left, maxi);
        preOrder(root -> right, maxi);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int maxi = 1 << 31;
        preOrder(root, maxi);
        if(maxi <= 0) {
            return maxi;
        }
        pair<int, int> result = sumHelper(root);
        return max(result.first, result.second);
    }
};

int main() {
	TreeNode* root = new TreeNode(1);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(3);
	Solution s;
	cout << s.maxPathSum(root) << endl;
	return 0;
}