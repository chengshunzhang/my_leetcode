#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(1 << 31), * l = left, * r = right;
        ListNode* p = dummy;
        while(l != NULL && r != NULL) {
            if(l -> val < r -> val) {
                p -> next = l;
                l = l -> next;
            } else {
                p -> next = r;
                r = r -> next;
            }
            p = p -> next;
        }
        if(l != NULL) {
            p -> next = l;
        }
        if(r != NULL) {
            p -> next = r;
        }
        return dummy -> next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode* fast = head, * slow = head, * l = head;
        while(fast -> next != NULL && fast -> next -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* r = slow -> next;
        slow -> next = NULL;
        head = merge(sortList(l), sortList(r));
        return head;
    }
};

int main() {
	ListNode* head = new ListNode(4);
	head -> next = new ListNode(2); head -> next -> next = new ListNode(1); head -> next -> next -> next = new ListNode(3);
	Solution s;
	ListNode* p = s.sortList(head);
	while(p != NULL) {
		cout << p -> val << ' ';
		p = p -> next;
	}
	cout << endl;
	return 0;
}