#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void helper(TreeNode*& root, ListNode* head) {
        ListNode* mid = head, * fast = head, * pre = NULL;
        while(fast != NULL) {
            fast = fast -> next;
            if(fast == NULL) {
                break;
            } else {
                fast = fast -> next;
                mid = mid -> next;
                pre == NULL ? pre = head : pre = pre -> next;
            }
        }
        root = new TreeNode(mid -> val);
        if(pre != NULL) {
            pre -> next = NULL;
            helper(root -> left, head);
        }
        if(mid -> next != NULL) {
            helper(root -> right, mid -> next);
        }
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        TreeNode* root = NULL;
        helper(root, head);
        return root;
    }
};

int main() {
	int p[] = {-10,-3,0,5,9};
	ListNode* head = new ListNode(-10);
	ListNode* pt = head;
	for(int i = 1; i < 5; i++) {
		pt -> next = new ListNode(p[i]);
		pt = pt -> next;
	}
	Solution s;
    TreeNode* root = s.sortedListToBST(head);
    cout << root -> right -> left -> val << endl;
    return 0;
}