#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k == 0) {
            return head;
        }
        ListNode* fast = head, * slow = head;
        int n = 0;
        while(n < k) {
            fast = fast -> next;
            n++;
            if(fast == NULL) {
                fast = head;
                k = k % n;
                if(k == 0) {
                    return head;
                }
                n = 0;
            }
        }
        while(fast -> next != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode* temp = slow -> next;
        slow -> next = NULL;
        fast -> next = head;
        head = temp;
        return head;
    }
};

int main() {
	ListNode* head = new ListNode(1), * p = head;
	for(int i = 2; i < 6; i++) {
		p -> next = new ListNode(i);
		p = p -> next;
	}
	Solution s;
	head = s.rotateRight(head, 2);
	p = head;
	while(p != NULL) {
		cout << p -> val << ' ';
		p = p -> next;
	}
	cout << endl;
	return 0;
}