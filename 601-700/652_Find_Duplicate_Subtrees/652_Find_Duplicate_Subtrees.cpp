#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    string helper(TreeNode* root, unordered_map<string, bool>& structures, vector<TreeNode*>& result) {
        if(root == NULL) {
            return "NULL";
        }
        string structure = to_string(root -> val) + 'l' + helper(root -> left, structures, result) + 'r' + helper(root -> right, structures, result);
        if(!structures.count(structure)) {
            structures[structure] = true;
        } else if(structures[structure] == true) {
            result.push_back(root);
            structures[structure] = false;
        }
        return structure;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        if(root == NULL) {
            return result;
        }
        unordered_map<string, bool> structures;
        helper(root -> left, structures, result);
        helper(root -> right ,structures, result);
        return result;
    }
};

int main() {
	TreeNode* root = new TreeNode(1);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(3);
	root -> left -> left = new TreeNode(4);
	root -> right -> left = new TreeNode(2);
	root -> right -> left -> left = new TreeNode(4);
	root -> right -> right = new TreeNode(4);
	Solution s;
	vector<TreeNode*> res = s.findDuplicateSubtrees(root);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] -> val << ' ';
	}
	cout << endl;
	return 0;
}