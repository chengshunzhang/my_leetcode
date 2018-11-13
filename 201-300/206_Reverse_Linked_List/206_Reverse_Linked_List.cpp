#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode* pre = NULL, * temp = NULL;
        while(head != NULL) {
            temp = head -> next;
            head -> next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
};

int main() {
	ListNode* head = new ListNode(1);
	head -> next = new ListNode(2);
	head -> next -> next = new ListNode(3);
	Solution s;
	head = s.reverseList(head);
	for(ListNode* p = head; p != NULL; p = p -> next) {
		cout << p -> val << "->";
	}
	cout << "NULL" << endl;
	return 0;
}