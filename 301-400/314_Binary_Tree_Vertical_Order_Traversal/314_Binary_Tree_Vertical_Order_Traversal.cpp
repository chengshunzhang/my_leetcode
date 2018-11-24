#include <queue>
#include <vector>
#include <unordered_map>
#include <list>
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
    void levelOrder(TreeNode* root, unordered_map<int, list<int> >& hash, int col, int& minCol, int& maxCol) {
        if(root == NULL) {
            return;
        }
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 0));
        while(!q.empty()) {
            TreeNode* temp = q.front().first;
            int col = q.front().second;
            q.pop();
            hash[temp -> val].push_back(col);
            if(col < minCol) {
                minCol = col;
            }
            if(col > maxCol) {
                maxCol = col;
            }
            if(temp -> left) {
                q.push(make_pair(temp -> left, col - 1));
            }
            if(temp -> right) {
                q.push(make_pair(temp -> right, col + 1));
            }
        }
    }
    void verticalOrder(TreeNode* root, unordered_map<int, list<int> >& hash, int& minCol, vector<vector<int> >& result) {
        if(root == NULL) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            int idx = hash[temp -> val].front() - minCol;
            hash[temp -> val].pop_front();
            result[idx].push_back(temp -> val);
            if(temp -> left) {
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
public:
    vector<vector<int> > verticalOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(root == NULL) {
            return result;
        }
        unordered_map<int, list<int> > hash;
        int minCol = INT_MAX, maxCol = INT_MIN;
        levelOrder(root, hash, 0, minCol, maxCol);
        result.resize(maxCol - minCol + 1);
        verticalOrder(root, hash, minCol, result);
        return result;
    }
};

int main() {
	int n[] = {3,9,20,INT_MAX,INT_MAX,15,7}, pos = 0;
	TreeNode* root = new TreeNode(n[pos++]);
	queue<TreeNode*> q;
	q.push(root);
	while(pos < 7) {
		TreeNode* temp = q.front();
		q.pop();
		if(n[pos] != INT_MAX) {
			temp -> left = new TreeNode(n[pos]);
			q.push(temp -> left);
		}
		pos++;
		if(n[pos] != INT_MAX) {
			temp -> right = new TreeNode(n[pos]);
			q.push(temp -> right);
		}
		pos++;
	}
	Solution s;
	vector<vector<int> > res = s.verticalOrder(root);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}