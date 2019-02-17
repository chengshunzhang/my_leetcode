#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(-1), * p = head, * pre = dummy;
        ListNode* dummyLarger = new ListNode(-1), * q = dummyLarger;
        dummy -> next = head;
        while(p) {
            if(p -> val >= x) {
                q -> next = p;
                q = q -> next;
                pre -> next = p -> next;
                p = pre -> next;
            } else {
                p = p -> next;
                pre = pre -> next;
            }
        }
        q -> next = NULL;
        pre -> next = dummyLarger -> next;
        return dummy -> next;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1), * p = head;
    int nums[] = {1, 4, 3, 2, 5, 2}, x = 3;
    for(int i = 1; i < 6; i++) {
        p -> next = new ListNode(nums[i]);
        p = p -> next;
    }
    head = s.partition(head, x);
    p = head;
    while(p) {
        cout << p -> val << " -> ";
        p = p -> next;
    }
    cout << "NULL" << endl;
    return 0;
}