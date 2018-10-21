#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode* pre = NULL, * cur = head, * ahead;
        while(cur != NULL) {
            ahead = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = ahead;
        }
        return pre;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }
        l1 = reverse(l1);
        l2 = reverse(l2);
        int temp = l1 -> val + l2 -> val, sum = temp % 10, carry = temp / 10;
        ListNode* result = new ListNode(sum), * p = l1 -> next, * q = l2 -> next, * res = result;
        while(p != NULL && q != NULL) {
            temp = p -> val + q -> val + carry;
            sum = temp % 10;
            carry = temp / 10;
            res -> next = new ListNode(sum);
            res = res -> next;
            p = p -> next;
            q = q -> next;
        }
        if(p == NULL && q == NULL && carry == 1) {
            res -> next = new ListNode(1);
        }
        if(p != NULL) {
            res -> next = p;
            if(carry == 1) {
                while(p -> val == 9 && p -> next != NULL) {
                    p -> val = 0;
                    p = p -> next;
                }
                if(p -> val == 9 && p -> next == NULL) {
                    p -> val = 0;
                    p -> next = new ListNode(1);
                } else {
                    p -> val += 1;
                }
            }
        }
        if(q != NULL) {
            res -> next = q;
            if(carry == 1) {
                while(q -> val == 9 && q -> next != NULL) {
                    q -> val = 0;
                    q = q -> next;
                }
                if(q -> val == 9 && q -> next == NULL) {
                    q -> val = 0;
                    q -> next = new ListNode(1);
                } else {
                    q -> val += 1;
                }
            }
        }
        return reverse(result);
    }
};

int main() {
	Solution s;
	ListNode* l1 = new ListNode(7);
	l1 -> next = new ListNode(2);
	l1 -> next -> next = new ListNode(4);
	l1 -> next -> next -> next = new ListNode(3);
	ListNode* l2 = new ListNode(5);
	l2 -> next = new ListNode(6);
	l2 -> next -> next = new ListNode(4);
	ListNode* res = s.addTwoNumbers(l1, l2);
	ListNode* p = res;
	while(p != NULL) {
		cout << p -> val;
		p = p -> next;
	}
	cout << endl;
	return 0;
}