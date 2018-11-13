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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL, * pre = NULL, * cur = NULL;
        ListNode* p = l1, * q = l2;
        while(p != NULL && q != NULL) {
            if(p -> val < q -> val) {
                cur = new ListNode(p -> val);
                p = p -> next;
            }
            else {
                cur = new ListNode(q -> val);
                q = q -> next;
            }
            if(result == NULL)
                result = pre = cur;
            else {
                pre -> next = cur;
                pre = cur;
            }
        }
        if(p != NULL)
            cur == NULL ? result = p : cur -> next = p;
        if(q != NULL)
            cur == NULL ? result = q : cur -> next = q;
        return result;
    }
};

int main() {
	ListNode* p1, * p2;
	p1 = new ListNode(1); p1 -> next = new ListNode(2); p1 -> next -> next = new ListNode(4);
	p2 = new ListNode(1); p2 -> next = new ListNode(3); p2 -> next -> next = new ListNode(4);
	Solution s;
	ListNode* res = s.mergeTwoLists(p1, p2);
	ListNode* p = res;
	while(p != NULL) {
		cout << p -> val << ' ';
		p = p -> next;
	}
	cout << endl;
	return 0;
}