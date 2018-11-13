#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(root == NULL) {
            return result;
        }
        vector<int> temp;
        deque<TreeNode*> q;
        temp.push_back(root -> val);
        q.push_back(root);
        if(root -> left == NULL && root -> right == NULL) {
            result.push_back(temp);
            return result;
        } else if(root -> left == NULL){
            q.push_back(root -> right);
        } else if(root -> right == NULL) {
            q.push_back(root -> left);
        } else {
            q.push_back(root -> left);
            q.push_back(root -> right);
        }
        while(q.size() > 1) {
            TreeNode* p = q.front();
            if(p == root) {
                result.push_back(temp);
                temp.clear();
                q.push_back(root);
                q.pop_front();
                p = q.front();
            }
            temp.push_back(p -> val);
            q.pop_front();
            if(p -> left != NULL) {
                q.push_back(p -> left);
            }
            if(p -> right != NULL) {
                q.push_back(p -> right);
            }
        }
        result.push_back(temp);
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
    vector<vector<int> > res = s.levelOrder(root);
    for(int i = 0; i < res.size(); i++) {
    	for(int j = 0; j < res[i].size(); j++) {
    		cout << res[i][j] << ' ';
    	}
    	cout << endl;
    }
    return 0;
}