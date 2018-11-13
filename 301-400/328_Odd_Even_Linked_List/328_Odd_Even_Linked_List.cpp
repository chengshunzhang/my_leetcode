#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode* odd = head, * even = head -> next, * start = even;
        while(even != NULL && even -> next != NULL) {
            odd -> next = even -> next;
            odd = odd -> next;
            even -> next = odd -> next;
            even = even -> next;
        }
        odd -> next = start;
        return head;
    }
};

int main() {
	ListNode* head = new ListNode(1), * p = head;
	for(int i = 2; i <= 5; i++) {
		p -> next = new ListNode(i);
		p = p -> next;
	}
	Solution s;
	head = s.oddEvenList(head);
	p = head;
	while(p != NULL) {
		cout << p -> val << " -> ";
		p = p -> next;
	}
	cout << "NULL" << endl;
	return 0;
}