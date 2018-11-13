#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* pre;
        while(node -> next != NULL) {
            node -> val = node -> next -> val;
            pre = node;
            node = node -> next;
        }
        pre -> next = NULL;
        delete node;
    }
};

int main() {
	ListNode* head = new ListNode(4);
	head -> next = new ListNode(5);
	head -> next -> next = new ListNode(1);
	head -> next -> next -> next = new ListNode(9);
	Solution s;
	s.deleteNode(head -> next);
	for(ListNode* p = head; p != NULL; p = p -> next) {
		cout << p -> val << "->";
	}
	cout << "NULL" << endl;
	return 0;
}