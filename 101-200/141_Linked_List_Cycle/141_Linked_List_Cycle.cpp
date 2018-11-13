#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) {
            return false;
        }
        ListNode* fast = head, * slow = head;
        while(fast != NULL) {
            fast = fast -> next;
            if(fast != NULL) {
                fast = fast -> next;
            } else {
                return false;
            }
            slow = slow -> next;
            if(fast == slow) {
                return true;
            }
        }
        return false;
    }
};

int main() {
	ListNode* head = new ListNode(8);
	head -> next = new ListNode(10);
	Solution s;
	cout << s.hasCycle(head) << endl;
	return 0;
}