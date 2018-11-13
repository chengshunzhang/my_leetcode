#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void helper(TreeNode*& root, vector<int>& nums, int left, int right) {
        int mid = left + (right - left) / 2;
        root = new TreeNode(nums[mid]);
        if(left < mid) {
            helper(root -> left, nums, left, mid - 1);
        }
        if(mid < right) {
            helper(root -> right, nums, mid + 1, right);
        }
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        if(nums.empty()) {
            return NULL;
        }
        helper(root, nums, 0, nums.size() - 1);
        return root;
    }
};

int main() {
	int p[] = {-10,-3,0,5,9};
	vector<int> nums(p,p+5);
	Solution s;
    TreeNode* root = s.sortedArrayToBST(nums);
    return 0;
}