#include <vector>
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
    void inOrder(TreeNode* root, vector<int>& arr) {
        if(root == NULL) {
            return;
        }
        inOrder(root -> left, arr);
        arr.push_back(root -> val);
        inOrder(root -> right, arr);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inOrder(root, arr);
        int left = 0, right = arr.size() - 1;
        while(left < right) {
            int sum = arr[left] + arr[right];
            if(sum == k) {
                return true;
            } else if(sum < k) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};

int main() {
	TreeNode* root = new TreeNode(5);
	root -> left = new TreeNode(3);
	root -> right = new TreeNode(6);
	root -> left -> left = new TreeNode(2);
	root -> left -> right = new TreeNode(4);
	root -> right -> right = new TreeNode(7);
	Solution s;
	cout << s.findTarget(root, 9) << endl;
	return 0;
}