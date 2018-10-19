#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(root == NULL) {
            return result;
        }
        vector<int> nodes;
        bool reverse = false;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL) {
                if(reverse) {
                    for(int i = 0, j = nodes.size() - 1; i < j; i++, j--) {
                        int tmp = nodes[i];
                        nodes[i] = nodes[j];
                        nodes[j] = tmp;
                    }
                    reverse = false;
                } else {
                    reverse = true;
                }
                result.push_back(nodes);
                if(q.empty()) {
                    break;
                }
                nodes.clear();
                q.push(NULL);
            }
            if(temp != NULL) {
                nodes.push_back(temp -> val);
                if(temp -> left != NULL) {
                    q.push(temp -> left);
                }
                if(temp -> right != NULL) {
                    q.push(temp -> right);
                }
            }
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
    		TreeNode* p = new TreeNode(n[i]);
    		if(i % 2 == 1) {
    			nodes[(i - 1) / 2] -> left = p;
    		} else {
    			nodes[(i - 1) / 2] -> right = p;
    		}
    		nodes.push_back(p);
    	}
    }
    Solution s;
    vector<vector<int> > res = s.zigzagLevelOrder(root);
    for(int i = 0; i < res.size(); i++) {
    	for(int j = 0; j < res[i].size(); j++) {
    		cout << res[i][j] << ' ';
    	}
    	cout << endl;
    }
	return 0;
}