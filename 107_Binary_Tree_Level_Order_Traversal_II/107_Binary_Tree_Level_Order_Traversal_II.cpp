#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        if(root == NULL) {
            return result;
        }
        vector<int> temp;
        temp.push_back(root -> val);
        result.push_back(temp);
        temp.clear();
        deque<TreeNode*> q;
        if(root -> left == NULL && root -> right == NULL) {
            return result;
        }
        if(root -> left != NULL) {
            q.push_back(root -> left);
        }
        if(root -> right != NULL) {
            q.push_back(root -> right);
        }
        q.push_back(root);
        while(q.size() > 1) {
            TreeNode* p = q.front();
            q.pop_front();
            if(p == root) {
                q.push_back(root);
                p = q.front();
                q.pop_front();
                result.push_back(temp);
                temp.clear();
            }
            temp.push_back(p -> val);
            if(p -> left != NULL) {
                q.push_back(p -> left);
            }
            if(p -> right != NULL) {
                q.push_back(p -> right);
            }
        }
        result.push_back(temp);
        int sz = result.size();
        for(int i = 0, j = sz - 1; i < j; i++, j--) {
            temp = result[i];
            result[i] = result[j];
            result[j] = temp;
        }
        return result;
    }
};

int main() {
	int n[] = {3,9,20,1<<31,1<<31,15,7};
    TreeNode* root = new TreeNode(n[0]);
    vector<TreeNode*> nodes;
    nodes.push_back(root);
    for(int i = 1; i < 7; i++) {
    	if(n[i] != (1 << 31)) {
    		TreeNode** p;
    		if(i % 2 == 1) {
    			p = & nodes[(i - 1) / 2] -> left;
    		} else {
    			p = & nodes[(i - 1) / 2] -> right;
    		}
    		*p = new TreeNode(n[i]);
    		nodes.push_back(*p);
    	}
    }
    Solution s;
    vector<vector<int> > res = s.levelOrderBottom(root);
    for(int i = 0; i < res.size(); i++) {
    	for(int j = 0; j < res[i].size(); j++) {
    		cout << res[i][j] << ' ';
    	}
    	cout << endl;
    }
    return 0;
}