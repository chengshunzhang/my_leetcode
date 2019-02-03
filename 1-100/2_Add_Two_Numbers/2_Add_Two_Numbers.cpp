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
        ListNode* p = l1, * q = l2, * dummy = new ListNode(0), * result_ptr = dummy;
        int carry = 0, add;
        while(p || q) {
            int sum = 0;
            if(p) {
                sum += p -> val;
                p = p -> next;
            }
            if(q) {
                sum += q -> val;
                q = q -> next;
            }
            sum += carry;
            add = sum % 10;
            carry = sum / 10;
            result_ptr -> next = new ListNode(add);
            result_ptr = result_ptr -> next;
        }
        if(carry) {
            result_ptr -> next = new ListNode(carry);
        }
        return dummy -> next;
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