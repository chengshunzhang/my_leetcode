#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) {
            return NULL;
        }
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* fast = head, * slow = head, * pre = dummy;
        for(int i = 1; i < n; i++) {
            fast = fast -> next;
        }
        while(fast -> next != NULL) {
            pre = slow;
            fast = fast -> next;
            slow = slow -> next;
        }
        pre -> next = slow -> next;
        delete slow;
        return dummy -> next;
    }
};

int main() {
	ListNode* head = new ListNode(1);
	head -> next = new ListNode(2);
	head -> next -> next = new ListNode(3);
	head -> next -> next -> next = new ListNode(4);
	head -> next -> next -> next -> next = new ListNode(5);
	Solution s;
	head = s.removeNthFromEnd(head, 2);
	ListNode* p = head;
	while(p != NULL) {
		cout << p -> val << "-> ";
		p = p -> next;
	}
	cout << "NULL" << endl;
	return 0;
}