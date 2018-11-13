#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1, * q = l2, * result = NULL, * result_pt = NULL;
        int sum, carry = 0, add;
        while(p != NULL && q != NULL) {
            sum = p -> val + q -> val + carry;
            carry = sum / 10;
            add = sum % 10;
            if(result == NULL) {
                result = new ListNode(add);
                result_pt = result;
            } else {
                result_pt -> next = new ListNode(add);
                result_pt = result_pt -> next;
            }
            p = p -> next;
            q = q -> next;
        }
        while(p != NULL) {
            sum = p -> val + carry;
            carry = sum / 10;
            add = sum % 10;
            result_pt -> next = new ListNode(add);
            result_pt = result_pt -> next;
            p = p -> next;
        }
        while(q != NULL) {
            sum = q -> val + carry;
            carry = sum / 10;
            add = sum % 10;
            result_pt -> next = new ListNode(add);
            result_pt = result_pt -> next;
            q = q -> next;
        }
        if(carry) {
            result_pt -> next = new ListNode(carry);
        }
        return result;
    }
};

int main() {
	ListNode* l1 = new ListNode(2); l1 -> next = new ListNode(4); l1 -> next -> next = new ListNode(3);
	ListNode* l2 = new ListNode(5); l2 -> next = new ListNode(6); l2 -> next -> next = new ListNode(4);
	Solution s;
	ListNode* res = s.addTwoNumbers(l1, l2);
	ListNode* p = res;
	while(p != NULL) {
		cout << p -> val << ' ';
        p = p -> next;
	} 
	cout << endl;
	return 0;
}