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
private:
    void helper(TreeNode* root, vector<int>& result, int K) {
        if(root == NULL) {
            return;
        }
        if(K == 0) {
            result.push_back(root -> val);
            return;
        }
        helper(root -> left, result, K - 1);
        helper(root -> right, result, K - 1);
    }
    int findTargetDistance(TreeNode* root, vector<int>& result, int target, int K) {
        if(root == NULL) {
            return -1;
        }
        if(root -> val == target) {
            helper(root -> left, result, K - 1);
            helper(root -> right, result, K - 1);
            return 0;
        }
        int leftDist = findTargetDistance(root -> left, result, target, K) + 1;
        int rightDist = findTargetDistance(root -> right, result, target, K) + 1;
        if(leftDist) {
            if(leftDist == K) {
                result.push_back(root -> val);
            }
            if(leftDist < K) {
                helper(root -> right, result, K - leftDist - 1);
            }
            return leftDist;
        }
        if(rightDist) {
            if(rightDist == K) {
                result.push_back(root -> val);
            }
            if(rightDist < K) {
                helper(root -> left, result, K - rightDist - 1);
            }
            return rightDist;
        }
        return -1;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> result;
        if(K == 0) {
            result.push_back(target -> val);
        } else {
           findTargetDistance(root, result, target -> val, K); 
        }
        return result;
    }
};

int main() {
	Solution s;
	int n[] = {3,5,1,6,2,0,8,1<<31,1<<31,7,4}, pos = 0;
	TreeNode* root = new TreeNode(n[pos++]);
	queue<TreeNode*> q;
	q.push(root);
	while(pos < 11) {
		TreeNode* temp = q.front();
		q.pop();
		if(n[pos] != (1<<31)) {
			temp -> left = new TreeNode(n[pos]);
			q.push(temp -> left);
		}
		pos++;
		if(n[pos] != (1<<31)) {
			temp -> right = new TreeNode(n[pos]);
			q.push(temp -> right);
		}
		pos++;
	}
	TreeNode* target = root -> left;
	vector<int> res = s.distanceK(root, target, 2);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}