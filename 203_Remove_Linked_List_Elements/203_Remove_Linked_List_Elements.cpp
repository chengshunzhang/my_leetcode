#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(1 << 31);
        dummy -> next = head;
        ListNode* p = dummy;
        while(p -> next != NULL) {
            if(p -> next -> val == val) {
                p -> next = p -> next -> next;
            } else {
                p = p -> next;
            }
        }
        return dummy -> next;
    }
};

int main() {
	int n[] = {1,2,6,3,4,5,6};
	ListNode* head = new ListNode(1);
	ListNode* p = head;
	for(int i = 1; i < 7; i++) {
		p -> next = new ListNode(n[i]);
		p = p -> next;
	}
	Solution s;
	p = s.removeElements(head, 6);
	while(p != NULL) {
		cout << p -> val << ' ';
		p = p -> next;
	}
	cout << endl;
	return 0;
}