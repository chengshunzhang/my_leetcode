#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) {
            return NULL;
        }
        ListNode * fast = head, * slow = head, * start = head;
        while(fast != NULL) {
            fast = fast -> next;
            if(fast == NULL) {
                return NULL;
            } else {
                fast = fast -> next;
            }
            slow = slow -> next;
            if(fast == slow) {
                break;
            }
        }
        if(fast == NULL) {
            return NULL;
        } else {
            while(start != slow) {
                start = start -> next;
                slow = slow -> next;
            }
            return start;
        }
    }
};

int main() {
	Solution s;
	ListNode* head = new ListNode(8);
	head -> next = new ListNode(10);
	head -> next -> next = head;
	ListNode* result = s.detectCycle(head);
	cout << result -> val << endl;
	return 0;
}