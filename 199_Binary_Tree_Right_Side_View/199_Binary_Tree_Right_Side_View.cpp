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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            TreeNode* p = q.front();
            q.pop();
            if(p != NULL) {
                if(p -> left != NULL) {
                    q.push(p -> left);
                }
                if(p -> right != NULL) {
                    q.push(p -> right);
                }
                if(!q.empty() && q.front() == NULL) {
                    result.push_back(p -> val);
                }
            } else if(!q.empty()) {
                q.push(NULL);
            }
        }
        return result;
    }
};

int main() {
	int n[] = {1,2,3,1<<31,5,1<<31,4};
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
    vector<int> res = s.rightSideView(root);
    for(int i = 0; i < res.size(); i++) {
    	cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}