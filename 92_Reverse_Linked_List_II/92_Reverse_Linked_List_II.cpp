#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head -> next == NULL || m == n) {
            return head;
        }
        int num = 1;
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* cur = head, * pre = dummy, * ahead, * before = dummy, * first = head;
        while(num < m) {
            pre = cur;
            cur = cur -> next;
            before = before -> next;
            first = first -> next;
            num++;
        }
        while(num <= n) {
            ahead = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = ahead;
            num++;
        }
        first -> next = cur;
        before -> next = pre;
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
	head = s.reverseBetween(head, 2, 4);
	ListNode* p = head;
	while(p != NULL) {
		cout << p -> val << "-> ";
		p = p -> next;
	}
	cout << "NULL" << endl;
	return 0;
}