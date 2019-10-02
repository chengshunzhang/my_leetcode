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
    void helper(TreeNode* root, double target, int k, priority_queue<pair<double, int>>& pq) {
        if(root == NULL) {
            return;
        }
        double diff = abs(root -> val - target);
        if(pq.size() < k || diff < pq.top().first) {
            if(pq.size() == k) {
                pq.pop();
            }
            pq.push(make_pair(diff, root -> val));
        }
        helper(root -> left, target, k, pq);
        helper(root -> right, target, k, pq);
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double, int>> pq;
        vector<int> result;
        helper(root, target, k, pq);
        while(!pq.empty()) {
            pair<double, int> temp = pq.top();
            pq.pop();
            result.push_back(temp.second);
        }
        return result;
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