#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        ListNode* p = head -> next, * pre = head;
        while(p != NULL) {
            if(p -> val == pre -> val) {
                pre -> next = p -> next;
                delete p;
                p = pre -> next;
            } else {
                pre = p;
                p = pre -> next;
            }
        }
        return head;
    }
};

int main() {
	ListNode* head = new ListNode(1);
	head -> next = new ListNode(1);
	head -> next -> next = new ListNode(2);
	Solution s;
	ListNode* p = s.deleteDuplicates(head);
	while(p != NULL) {
		cout << p -> val << endl;
		p = p -> next;
	}
	return 0;
}