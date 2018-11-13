#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        ListNode* dummy = new ListNode(1 << 31);
        dummy -> next = head;
        ListNode* last = head, * scan = head -> next;
        while(scan != NULL) {
            ListNode* p = dummy;
            while(p != last && p -> next -> val < scan -> val) {
                p = p -> next;
            }
            if(p == last) {
                last = last -> next;
            } else {
                last -> next = scan -> next;
                scan -> next = p -> next;
                p -> next = scan;
            }
            scan = last -> next;
        }
        return dummy -> next;
    }
};

int main() {
	Solution s;
	ListNode* head = new ListNode(8);
	ListNode* ph = head;
	for(int i = 2; i < 5; i++) {
		ListNode* p = new ListNode(i);
		ph -> next = p;
		ph = ph -> next;
	}
	ph = s.insertionSortList(head);
	while(ph != NULL) {
		cout << ph -> val << endl;
		ph = ph -> next;
	}
	return 0;
}