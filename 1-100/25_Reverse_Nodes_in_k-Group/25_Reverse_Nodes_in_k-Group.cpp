#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k == 1) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* pre = NULL, * cur = head, * ahead, * preGroup = dummy, * curGroup = head, * nextGroup = head;
        while(nextGroup) {
            for(int i = 0; i < k; i++) {
                if(nextGroup == NULL) {
                    return dummy -> next;
                }
                nextGroup = nextGroup -> next;
            }
            while(cur != nextGroup) {
                ahead = cur -> next;
                cur -> next = pre;
                pre = cur;
                cur = ahead;
            }
            preGroup -> next = pre;
            curGroup -> next = nextGroup;
            preGroup = curGroup;
            curGroup = nextGroup;
        }
        return dummy -> next;
    }
};

int main() {
	ListNode* head = new ListNode(1), * p = head;
	for(int i = 2; i < 6; i++) {
		p -> next = new ListNode(i);
		p = p -> next;
	}
	Solution s;
	head = s.reverseKGroup(head, 2);
	p = head;
	while(p) {
		cout << p -> val << " -> ";
		p = p -> next;
	}
	cout << "NULL" << endl;
	return 0;
}