#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode* pre = head, * cur = head -> next;
        head = cur;
        while(cur != NULL) {
            pre -> next = cur -> next;
            cur -> next = pre;
            pre = pre -> next;
            if(pre != NULL) {
                if(pre -> next != NULL) {
                    cur -> next -> next = pre -> next;
                    cur = pre -> next;
                } else {
                    cur -> next -> next = pre;
                    break;
                }
            } else {
                break;
            }
        }
        return head;
    }
};

int main() {
	ListNode* head = new ListNode(1);
	head -> next = new ListNode(2);
	head -> next -> next = new ListNode(3);
	head -> next -> next -> next = new ListNode(4);
	Solution s;
	head = s.swapPairs(head);
	ListNode* p = head;
	while(p != NULL) {
		cout << p -> val << ' ';
		p = p -> next;
	}
	cout << endl;
	return 0;
}