#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL) {
            return;
        }
        vector<ListNode*> pointers;
        int num = 1;
        ListNode* fast = head, * slow = head, * cur = head;
        while(fast -> next != NULL && fast -> next -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
            num++;
        }
        slow = slow -> next;
        while(slow != NULL) {
            pointers.push_back(slow);
            slow = slow -> next;
            num++;
        }
        while(!pointers.empty()) {
            slow = pointers.back();
            pointers.pop_back();
            slow -> next = cur -> next;
            cur -> next = slow;
            if(!pointers.empty()) {
                cur = cur -> next -> next;
            } else {
                if(num % 2 == 0) {
                    cur -> next -> next = NULL;
                } else {
                    cur -> next -> next -> next = NULL;
                }
            }
        }
    }
};

int main() {
	Solution s;
	ListNode* head = new ListNode(1);
	ListNode* ph = head;
	for(int i = 2; i < 5; i++) {
		ListNode* p = new ListNode(i);
		ph -> next = p;
		ph = ph -> next;
	}
	s.reorderList(head);
	ph = head;
	while(ph != NULL) {
		cout << ph -> val << endl;
		ph = ph -> next;
	}
	return 0;
}