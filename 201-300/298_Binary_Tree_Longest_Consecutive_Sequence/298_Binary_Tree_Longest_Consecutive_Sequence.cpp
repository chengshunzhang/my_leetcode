#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    pair<int, int> helper(TreeNode* root) {
        if(root == NULL) {
            return make_pair(0, 0);
        }
        pair<int, int> candidateL, candidateR;
        pair<int, int> leftRes = helper(root -> left), rightRes = helper(root -> right);
        if(root -> left && root -> val + 1 == root -> left -> val) {
            candidateL = make_pair(leftRes.first + 1, max(leftRes.first, leftRes.second));
        } else {
            candidateL = make_pair(1, max(leftRes.first, leftRes.second));
        }
        if(root -> right && root -> val + 1 == root -> right -> val) {
            candidateR = make_pair(rightRes.first + 1, max(rightRes.first, rightRes.second));
        } else {
            candidateR = make_pair(1, max(rightRes.first, rightRes.second));
        }
        pair<int, int> result;
        result.first = max(candidateL.first, candidateR.first);
        result.second = max(candidateL.second, candidateR.second);
        return result;
    }
public:
    int longestConsecutive(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        pair<int, int> result = helper(root);
        return max(result.first, result.second);
    }
};

int main() {
	TreeNode* root = new TreeNode(1);
	root -> right = new TreeNode(3);
	root -> right -> left = new TreeNode(2);
	root -> right -> right = new TreeNode(4);
	root -> right -> right -> right = new TreeNode(5);
	Solution s;
	cout << s.longestConsecutive(root) << endl;
	return 0;
}