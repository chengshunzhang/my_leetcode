#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void helper(TreeNode* root, double target, int k, deque<int>& dq) {
        if(root == NULL) {
            return;
        }
        helper(root -> left, target, k, dq);
        if(dq.size() < k || abs(root -> val - target) < abs(dq.front() - target)) {
            if(dq.size() == k) {
                dq.pop_front();
            }
            dq.push_back(root -> val);
        }
        helper(root -> right, target, k, dq);
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> dq;
        helper(root, target, k, dq);
        return vector<int> (dq.begin(), dq.end());
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root -> left = new TreeNode(2);
    root -> left -> left = new TreeNode(1);
    root -> left -> right = new TreeNode(3);
    root -> right = new TreeNode(5);
    Solution sol;
    double target = 3.714286;
    int k = 2;
    vector<int> result = sol.closestKValues(root, target, k);
    for(int val : result) {
        cout << val << ',';
    }
    cout << "\b \n";
    return 0;
}