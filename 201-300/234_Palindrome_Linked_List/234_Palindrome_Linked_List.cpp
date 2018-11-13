#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return true;
        }
        ListNode* pre = NULL, * slow = head, * post = slow -> next, * fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL) {
            fast = fast -> next -> next;
            slow -> next = pre;
            pre = slow;
            slow = post;
            post = post -> next;
        }
        if(fast -> next != NULL) {
            slow -> next = pre;
            while(post != NULL) {
                if(post -> val != slow -> val) {
                    return false;
                }
                post = post -> next;
                slow = slow -> next;
            } 
        } else {
            while(post != NULL) {
                if(post -> val != pre -> val) {
                    return false;
                }
                post = post -> next;
                pre = pre -> next;
            }
        }
        return true;
    }
};

int main() {
	ListNode* head = new ListNode(1);
	head -> next = new ListNode(2);
	head -> next -> next = new ListNode(2);
	head -> next -> next -> next = new ListNode(1);
	Solution s;
	cout << s.isPalindrome(head) << endl;
	return 0;
}